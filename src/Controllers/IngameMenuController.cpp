#include "Controllers/IngameMenuController.h"
#include "GUI/ClickableStructuresBuilder.h"
#include "GUI/ButtonsBuilder.h"

ctrl::IngameMenuController::IngameMenuController()
{
	font.loadFromFile("assets/fonts/cinematic.ttf");

	menuWindow = std::shared_ptr<gui::Window>(new gui::Window);
	menuWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>( new gui::GraphicComponent(textures->GetTexture("Window"))));
	CloseMenu();
	menuWindow->SetActive(false);

	gui::ButtonsBuilder buttonsBuilder;
	buttonsBuilder.SetFont(font);
	buttonsBuilder.SetTexture(textures->GetTexture("Button"));

	gui::ClickableStructuresBuilder clickabletStructures;
	clickabletStructures.Add(buttonsBuilder.BuildTextButton("Save", { 0,0 }));
	clickabletStructures.Add(buttonsBuilder.BuildTextButton("Load", { 0,0 }));
	clickabletStructures.Add(buttonsBuilder.BuildTextButton("Resume", { 0,0 }))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		menuWindow->SetActive(false);
		CloseMenu(); 
			});
	clickabletStructures.Add(buttonsBuilder.BuildTextButton("Exit", { 0,0 }))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {renderWindow->close(); });
	clickabletStructures.SetPosition({ menuWindow->GetWindowArea().width / 2.f, menuWindow->GetWindowArea().height/2});
	menuWindow->Add(clickabletStructures.MakeVertical(menuWindow->GetWindowArea().height/2));
	menuWindow->SetPosition( { renderWindow->getSize().x / 2.f - menuWindow->GetWindowArea().width / 2, 0 });

	

}

ctrl::IngameMenuController::~IngameMenuController()
{
}

void ctrl::IngameMenuController::Update(sf::Time time)
{
	if (menuWindow->IsActive() == true && menuWindow->IsVisible() == false)
		OpenMenu();
	else if (menuWindow->IsActive() == false && menuWindow->IsVisible() == true)
		CloseMenu();
}

void ctrl::IngameMenuController::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::Escape) {
			if (currentLayer == 0 && menuWindow->IsActive() == false) {
				menuWindow->SetActive(true);
				currentLayer = 1;
			}
			else if (currentLayer == 1 && menuWindow->IsActive() == true) {
				menuWindow->SetActive(false);
			}
		}
	}

	menuWindow->HandleEvent(event);

}

void ctrl::IngameMenuController::Draw() const
{
	renderWindow->draw(*menuWindow);
}

void ctrl::IngameMenuController::OpenMenu()
{
	menuWindow->SetVisible(true);
}

void ctrl::IngameMenuController::CloseMenu()
{
	menuWindow->SetVisible(false);
	currentLayer = 0;
}
