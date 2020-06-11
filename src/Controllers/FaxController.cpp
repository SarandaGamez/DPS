#include "Controllers/FaxController.h"
#include "GUI/ButtonsBuilder.h"
#include "Gameplay/Action.h"

ctrl::FaxController::FaxController()
{
	paperTexture.loadFromFile("assets/graphics/GUI/Paper.png");
	windowTexture.loadFromFile("assets/graphics/GUI/ReportWindow.png");
	gui::ButtonsBuilder buttonsBuilder;

	reportWindow = std::shared_ptr<gui::Window>(new gui::Window());
	reportWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(windowTexture)));
	reportWindow->SetActive(false);
	reportWindow->SetPosition({renderWindow->getSize().x / 2.f - reportWindow->GetWindowArea().width / 2,
		renderWindow->getSize().y / 2.f - reportWindow->GetWindowArea().height / 2});

	reportButton = std::shared_ptr<gui::Button>(new gui::Button(paperTexture, { 1670, 630 }));
	reportButton->SetActive(false);
	reportButton->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		if (currentLayer == 0) {
			reportWindow->SetActive(true);
			reportButton->SetActive(false);
			currentLayer = 1;
		}
		});	

}

ctrl::FaxController::~FaxController()
{
}

void ctrl::FaxController::Update(sf::Time elapsedTime)
{
	reportWindow->Update(elapsedTime);
	if (reportWindow->IsActive() == true && reportWindow->IsVisible() == false)
		reportWindow->SetVisible(true);
	else if (reportWindow->IsActive() == false && reportWindow->IsVisible() == true) {
		reportWindow->SetVisible(false);
		currentLayer = 0;
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
		if (!reportWindow->GetWindowArea().contains(mousePosition) && currentLayer > 0 && reportWindow->IsActive())
			reportWindow->SetActive(false);
	}
	if (event.type == sf::Event::KeyPressed) {
		// Close Report with escape
		if (event.key.code == sf::Keyboard::Escape && currentLayer > 0 && reportWindow->IsActive()) {
			reportWindow->SetActive(false);
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
