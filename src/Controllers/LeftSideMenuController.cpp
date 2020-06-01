#include "Controllers/LeftSideMenuController.h"
#include "GUI/HoverableComponent.h"
#include "GUI/EventBehavior/SignalTypes.h"

ctrl::LeftSideMenuController::LeftSideMenuController()
{
	textures->Load("SideWindow", "assets/graphics/GUI/SideWindow.png");

	menuWindow = std::shared_ptr<gui::Window>(new gui::Window);
	menuWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent( textures->GetTexture("SideWindow") )));
	CloseMenu();

	auto hoverableRegion = std::shared_ptr<gui::HoverableComponent>(new gui::HoverableComponent);
	hoverableRegion->SetRegion(menuWindow->GetWindowArea());
	hoverableRegion->GetSignal(gui::SignalTypes::onMouseEnter).Connect([=]() {
		OpenMenu();
		currentLayer = 1;
		});
	hoverableRegion->GetSignal(gui::SignalTypes::onMouseLeave).Connect([=]() {
		CloseMenu();
		});

	menuWindow->Add(hoverableRegion);
}

ctrl::LeftSideMenuController::~LeftSideMenuController()
{
}

void ctrl::LeftSideMenuController::Update(sf::Time time)
{
	menuWindow->Update(time);
}

void ctrl::LeftSideMenuController::HandleEvent(sf::Event event)
{
	menuWindow->HandleEvent(event);
}

void ctrl::LeftSideMenuController::Draw() const
{
	renderWindow->draw(*menuWindow);
}

void ctrl::LeftSideMenuController::OpenMenu()
{
	menuWindow->SetVisible(true);
}

void ctrl::LeftSideMenuController::CloseMenu()
{
	menuWindow->SetVisible(false);
	currentLayer = 0;
}
