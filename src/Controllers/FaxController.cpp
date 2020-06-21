#include "Controllers/FaxController.h"
#include "GUI/ButtonsBuilder.h"
#include "Gameplay/Action.h"
#include "Utils/Collision.h"
#include "Utils/StringUtils.h"
#include "GUI/ComponentsBuilder.h"

ctrl::FaxController::FaxController()
{
	paperTexture.loadFromFile("assets/graphics/GUI/Paper.png");
	windowTexture.loadFromFile("assets/graphics/GUI/ReportWindow.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");
	gui::ButtonsBuilder buttonsBuilder;

	reportWindow = std::shared_ptr<gui::Window>(new gui::Window());
	reportWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(windowTexture)));
	reportWindow->SetActive(false); 
	reportWindow->SetVisible(false);

	reportButton = std::shared_ptr<gui::Button>(new gui::Button(paperTexture, { 1670, 630 }));
	reportButton->SetActive(false);
	reportButton->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		signals.Emit("OPEN_FAX");
		signals.Emit("CLICKED_FAX");
		});	

	std::string testingText = "Hello Comrade,\n\nThis is the first day of the service for the safety of the Graboria State. Until you will be able to praise the glory of the Greatest Leader you will have to complete the training.\n First of all you have to familiarize yourself with the tools given from the central planner.\n Open the notebook to see the next information.\n\n (You can finish reading the fax by clicking outside of it or by pressing escape button.)";
	testingText = utils::StringUtils::BreakLines(testingText, 35);
	reportText = gui::ComponentsBuilder::BuildTextComponent(font, 17, { 220,200 }, testingText);
	reportWindow->Add(reportText);

	reportWindow->SetPosition({ renderWindow->getSize().x / 2.f - reportWindow->GetWindowArea().width / 2,
		renderWindow->getSize().y / 2.f - reportWindow->GetWindowArea().height / 2 });
	
	signals["SHOW_FAX_BUTTON"].Connect([=]() {
		reportButton->SetActive(true);
		});
	signals["HIDE_FAX_BUTTON"].Connect([=]() {
		reportButton->SetActive(false);
		});
	signals["OPEN_FAX"].Connect([=]() {
		if (currentLayer == 0) {
			reportWindow->SetActive(true);
			reportButton->SetActive(false);
			currentLayer = 1;
		}
		});
	signals["CLOSE_FAX"].Connect([=]() {
		reportWindow->SetActive(false);
		});
}

ctrl::FaxController::~FaxController()
{
}

void ctrl::FaxController::Update(sf::Time elapsedTime)
{
	reportWindow->Update(elapsedTime);
	if (reportWindow->IsActive() == true && reportWindow->IsVisible() == false) {
		reportWindow->SetVisible(true);
		signals.Emit("OPENED_FAX");
	}
	else if (reportWindow->IsActive() == false && reportWindow->IsVisible() == true) {
		if (currentLayer >= 1) {
			reportWindow->SetVisible(false);
			currentLayer = 0;
			signals.Emit("CLOSED_FAX");
		}
	}
	if (reportButton->IsActive() == true && reportButton->IsVisible() == false)
		reportButton->SetVisible(true);
	else if (reportButton->IsActive() == false && reportButton->IsVisible() == true) {
		reportButton->SetVisible(false);
	}
}

void ctrl::FaxController::HandleEvent(sf::Event event)
{
	sf::Vector2f mousePosition = { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };


	// Close Report after clicking outside of it
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		if (Collision::PixelPerfectMouseTest(reportWindow->GetBackground()->GetSprite(), mousePosition) == false
			&& currentLayer > 0 && reportWindow->IsActive()) 
		{
			reportWindow->SetActive(false);
		}
	}
	if (event.type == sf::Event::KeyPressed) {
		// Close Report with escape
		if (event.key.code == sf::Keyboard::Escape && currentLayer > 0 && reportWindow->IsActive()) {
			signals.Emit("CLOSE_FAX");
		}
		// Generate new report
		if (event.key.code == sf::Keyboard::F && currentLayer == 0 && reportWindow->IsActive() == false) {
			reportButton->SetActive(true);
		}
	}

	if(currentLayer > 0)
		reportWindow->HandleEvent(event);
	if(currentLayer == 0)
		reportButton->HandleEvent(event);

}

void ctrl::FaxController::Draw() const
{
	renderWindow->draw(*reportWindow);
	renderWindow->draw(*reportButton);
}
