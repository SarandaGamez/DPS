#include "Controllers/IngameMenuController.h"
#include "GUI/ClickableStructuresBuilder.h"
#include "GUI/ButtonsBuilder.h"

ctrl::IngameMenuController::IngameMenuController()
{
	font.loadFromFile("assets/fonts/cinematic.ttf");

	menuWindow = std::shared_ptr<gui::Window>(new gui::Window);
	menuWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures->GetTexture("Window"))));
	CloseMenu();
	menuWindow->SetActive(false);

	gui::ButtonsBuilder buttonsBuilder;
	buttonsBuilder.SetFont(font);
	buttonsBuilder.SetTexture(textures->GetTexture("Button"));

	button = buttonsBuilder.BuildTextButton("Menu", { 0, (float)renderWindow->getSize().y - textures->GetTexture("Button").getSize().y });
	button->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		if (currentLayer == 0) {
			menuWindow->SetActive(true);
			currentLayer = 1;
		}
		});

	conditionSignals["IS_MENU_OPEN"].Connect([=]() {
		return menuWindow->IsActive();
		});
	conditionSignals["IS_MENU_CLOSED"].Connect([=]() {
		return !menuWindow->IsActive();
		});
	signals["SHOW_MENU_BUTTON"].Connect([=]() {
		button->SetActive(true);
		});
	signals["HIDE_MENU_BUTTON"].Connect([=]() {
		button->SetActive(false);
		});
	signals["OPEN_MENU"].Connect([=]() {
		menuWindow->SetActive(true);
		currentLayer = 1;
		});
	signals["CLOSE_MENU"].Connect([=]() {
		menuWindow->SetActive(false);
		CloseMenu();
		});

	gui::ClickableStructuresBuilder clickableStructures;
	clickableStructures.Add(buttonsBuilder.BuildTextButton("Save", { 0,0 }));
	clickableStructures.Add(buttonsBuilder.BuildTextButton("Load", { 0,0 }));
	clickableStructures.Add(buttonsBuilder.BuildTextButton("Resume", { 0,0 }))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		menuWindow->SetActive(false);
		CloseMenu();
			});
	clickableStructures.Add(buttonsBuilder.BuildTextButton("Exit", { 0,0 }))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {renderWindow->close(); });
	clickableStructures.SetPosition({ menuWindow->GetWindowArea().width / 2.f, menuWindow->GetWindowArea().height / 2 });
	menuWindow->Add(clickableStructures.MakeVertical(menuWindow->GetWindowArea().height / 2));
	menuWindow->SetPosition({ renderWindow->getSize().x / 2.f - menuWindow->GetWindowArea().width / 2, 0 });
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
	button->HandleEvent(event);

}

void ctrl::IngameMenuController::Draw() const
{
	renderWindow->draw(*menuWindow);
	if(currentLayer == 0)
		renderWindow->draw(*button);
}

void ctrl::IngameMenuController::OpenMenu()
{
	actions.Block(true);
	menuWindow->SetVisible(true);
	signals.Emit("OPENED_MENU");
}

void ctrl::IngameMenuController::CloseMenu()
{
	actions.Block(false);
	menuWindow->SetVisible(false);
	currentLayer = 0;
	signals.Emit("CLOSED_MENU");
}
