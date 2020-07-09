#include "Controllers/DebugController.h"
#include "GUI/ComponentsBuilder.h"
#include "GUI/DialogWindowBuilder.h"
#include <sstream>
#include <iomanip>

ctrl::DebugController::DebugController()
{
	textures->Load("DialogWindow", "assets/graphics/GUI/DialogWindow.png");
	textures->Load("Button", "assets/graphics/GUI/Button.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");

	gui::ComponentsBuilder componentsBuilder;
	debugText = componentsBuilder.BuildTextComponent(font, 20, { 20,20 }, "");
	dialogWindow = std::shared_ptr<gui::Window>(new gui::Window);
	dialogWindow->SetActive(false);
	dialogWindow->SetVisible(false);


	signals["DISPLAY_DIALOG"].Connect([=]() {
		if (arguments.size() == 1 && variables.CheckIfExists(arguments[0].substr(1))) {
			if (variables.IsType(arguments[0].substr(1), scripts::VariableType::text)) {
				std::string txt = std::any_cast<std::string>(variables.Get(arguments[0].substr(1)).GetValue());
				gui::DialogWindowBuilder dialogWindowBuilder(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures->GetTexture("DialogWindow"))));
				dialogWindowBuilder.SetCaption(txt, font);
				dialogWindowBuilder.AddOption("Close", font, textures->GetTexture("Button"))
					->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
					dialogWindow->SetActive(false);
						});
				dialogWindow = dialogWindowBuilder.GetResult();
				dialogWindow->SetPosition({ renderWindow->getSize().x / 2 - dialogWindow->GetWindowArea().width / 2, renderWindow->getSize().y / 2 - dialogWindow->GetWindowArea().height / 2 });
				dialogWindow->SetLayer(1);
				dialogWindow->SetActive(true);
				currentLayer = 1;
			}
		}
		});
}

ctrl::DebugController::~DebugController()
{
}

void ctrl::DebugController::Update(sf::Time time)
{
	if(isWindowClosed)
		renderWindow->close();

	auto mousePos = renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*renderWindow));
	std::stringstream ss;
	ss << std::fixed << std::setprecision(0) << mousePos.x << ":" << mousePos.y;
	debugText->SetText(ss.str());
	
	if (dialogWindow->IsActive() == true && dialogWindow->IsVisible() == false) {
		dialogWindow->SetVisible(true);
		signals.Emit("OPENED_DIALOG");
	}
	else if (dialogWindow->IsActive() == false && dialogWindow->IsVisible() == true) {
		dialogWindow->SetVisible(false);
		currentLayer = 0;
		signals.Emit("CLOSED_DIALOG");
	}
}

void ctrl::DebugController::HandleEvent(sf::Event event)
{
	if(currentLayer > 0)
		dialogWindow->HandleEvent(event);
}

void ctrl::DebugController::Draw() const
{
	renderWindow->draw(*debugText);
	if(currentLayer > 0)
		renderWindow->draw(*dialogWindow);
}
