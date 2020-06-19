#include "Controllers/MapController.h"
#include "GUI/ButtonsBuilder.h"
#include "Utils/Collision.h"

ctrl::MapController::MapController()
{
	mapWindowTexture.loadFromFile("assets/graphics/GUI/MapWindow.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");
	mapWindow = std::shared_ptr<gui::Window>(new gui::Window());
	mapWindow->SetLayer(1);
	mapWindow->SetBackground(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(mapWindowTexture)));

	gui::ButtonsBuilder buttonsBuilder;
	buttonsBuilder.SetFont(font);
	buttonsBuilder.SetTexture(textures->GetTexture("Button"));


	openMapButton = buttonsBuilder.BuildClickableRegion({ 850, 160, 400, 280 });
	openMapButton->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		if (currentLayer == 0 && mapWindow->IsActive() == false) {
			mapWindow->SetActive(true);
			currentLayer = 1;
			signals.Emit("OPENED_MAP");
		}
		});

	signals["OPEN_MAP"].Connect([=]() {
		mapWindow->SetActive(true);
		currentLayer = 1;
		signals.Emit("OPENED_MAP");
		});

	signals["CLOSE_MAP"].Connect([=]() {
		mapWindow->SetActive(false);
		signals.Emit("CLOSED_MAP");
		});

	signals["SHOW_MAP_BUTTON"].Connect([=]() {
		openMapButton->SetActive(true);
		});

	signals["HIDE_MAP_BUTTON"].Connect([=]() {
		openMapButton->SetActive(false);
		});

	auto placeButton = buttonsBuilder.BuildTextButton("Place1", { 70,430 });
	mapWindow->Add(placeButton);
	placeButton = buttonsBuilder.BuildTextButton("Place2", { 350,445 });
	mapWindow->Add(placeButton);
	placeButton = buttonsBuilder.BuildTextButton("Place3", { 650,505 });
	mapWindow->Add(placeButton);

	mapWindow->SetPosition({ renderWindow->getSize().x / 2 - mapWindow->GetWindowArea().width / 2, renderWindow->getSize().y / 2 - mapWindow->GetWindowArea().height / 2 });
	mapWindow->SetActive(false);
}

ctrl::MapController::~MapController()
{
}

void ctrl::MapController::Update(sf::Time time)
{
	mapWindow->Update(time);
	if (mapWindow->IsActive() == true && mapWindow->IsVisible() == false)
		mapWindow->SetVisible(true);
	else if (mapWindow->IsActive() == false && mapWindow->IsVisible() == true) {
		mapWindow->SetVisible(false);
		currentLayer = 0;
	}
}

void ctrl::MapController::HandleEvent(sf::Event event)
{
	sf::Vector2f mousePosition = { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };

	if (currentLayer == 0)
		openMapButton->HandleEvent(event);

	if (currentLayer == 1)
		mapWindow->HandleEvent(event);

	// Close the window after clicking outside of it
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		if (Collision::PixelPerfectMouseTest(mapWindow->GetBackground()->GetSprite(), mousePosition) == false) {
			mapWindow->SetActive(false);
			signals.Emit("CLOSED_MAP");
		}
	}
	// Close window with escape
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape && currentLayer > 0 && mapWindow->IsActive()) {
			mapWindow->SetActive(false);
			signals.Emit("CLOSED_MAP");
		}
	}
}

void ctrl::MapController::Draw() const
{
	if (currentLayer > 0) {
		renderWindow->draw(*mapWindow);
	}
}
