#include "Controllers/LeftSideMenuController.h"
#include "GUI/HoverableComponent.h"
#include "GUI/EventBehavior/SignalTypes.h"

ctrl::LeftSideMenuController::LeftSideMenuController()
{
	textures->Load("SideWindow", "assets/graphics/GUI/SideWindow.png");

	menuWindow = std::shared_ptr<gui::Window>(new gui::Window);
	menuWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent( textures->GetTexture("SideWindow") )));
	isMenuOpen = false;

	auto hoverableRegion = std::shared_ptr<gui::HoverableComponent>(new gui::HoverableComponent);
	hoverableRegion->SetRegion(menuWindow->GetWindowArea());
	hoverableRegion->GetSignal(gui::SignalTypes::onMouseEnter).Connect([=]() {
		if (currentLayer == 0 && isMenuOpen == false) {
			isMenuOpen = true;
		}
		});

	menuWindow->Add(hoverableRegion);
}

ctrl::LeftSideMenuController::~LeftSideMenuController()
{
}

void ctrl::LeftSideMenuController::Update(sf::Time time)
{
	sf::Vector2f mousePosition = renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*renderWindow));

	if (isMenuOpen == true && menuWindow->IsVisible() == false)
		menuWindow->SetVisible(true);

	if (menuWindow->IsVisible() == true){

		if (isMenuOpen == false || menuWindow->GetWindowArea().contains(mousePosition) == false || currentLayer != 0) {
			isMenuOpen = false;
			menuWindow->SetVisible(false);
		}
	}
}

void ctrl::LeftSideMenuController::HandleEvent(sf::Event event)
{
	menuWindow->HandleEvent(event);
}

void ctrl::LeftSideMenuController::Draw() const
{
	renderWindow->draw(*menuWindow);
}