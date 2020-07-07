#include "Controllers/LocationController.h"
#include "GUI/UICompositeBuilder.h"

ctrl::LocationController::LocationController()
{
	textures->Load("officeDesk", "assets/graphics/locations/desk.png");
	textures->Load("officeBgr", "assets/graphics/locations/office1.png");
	textures->Load("officeWindowView", "assets/graphics/locations/WindowCityscape1.png");
	textures->Load("officeChair", "assets/graphics/locations/chair.png");

	
	auto windowView = std::shared_ptr<gui::UIComponent>(new gui::GraphicComponent(textures->GetTexture("officeWindowView")));
	auto background = std::shared_ptr<gui::UIComponent>(new gui::GraphicComponent(textures->GetTexture("officeBgr")));
	auto desk = std::shared_ptr<gui::UIComponent>(new gui::GraphicComponent(textures->GetTexture("officeDesk")));
	auto chair = std::shared_ptr<gui::UIComponent>(new gui::GraphicComponent(textures->GetTexture("officeChair")));
	
	windowView->SetLayer(0);
	background->SetLayer(0);
	desk->SetLayer(4);
	chair->SetLayer(2);
	windowView->SetPosition({ 150,150 });
	chair->SetPosition({ renderWindow->getSize().x - 1250.f, renderWindow->getSize().y - 600.f });
	desk->SetPosition({ renderWindow->getSize().x - 1740.f, renderWindow->getSize().y - 500.f });

	drawablesList.push_back(windowView);
	drawablesList.push_back(background);
	drawablesList.push_back(chair);
	drawablesList.push_back(desk);

}

ctrl::LocationController::~LocationController()
{
}

void ctrl::LocationController::Update(sf::Time time)
{
}

void ctrl::LocationController::HandleEvent(sf::Event event)
{
}

void ctrl::LocationController::Draw() const
{
}
