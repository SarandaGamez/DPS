#include "States/GameState.h"
#include "States/OverState.h"
#include "StatesMachine.h"
#include "GUI/ComponentsBuilder.h"
#include "Controllers/NotebookController.h"
#include "Controllers/DebugController.h"
#include "Controllers/IngameMenuController.h"
#include "Controllers/LeftSideMenuController.h"
#include "Controllers/TurnsController.h"
#include "Controllers/FaxController.h"
#include "Controllers/DateController.h"
#include "Controllers/MapController.h"
#include "Controllers/GameController.h"
#include "Controllers/TriggersController.h"
#include "Controllers/LocationController.h"
#include <string>
#include "Utils/StringUtils.h"

#include <iostream>

using std::cout;
using std::endl;

void GameState::OnEnter()
{
	// Global assets and controllers initialization
	cout << "Loading textures" << endl;
	textures.Load("OfficeBackground", "assets/graphics/locations/ProsecutorsOffice.png");
	textures.Load("Window", "assets/graphics/GUI/Window.png");
	textures.Load("DialogWindow", "assets/graphics/GUI/DialogWindow.png");
	textures.Load("Button", "assets/graphics/GUI/Button.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");
	cout << "Loading textures done" << endl;

	ctrl::Controller::Initialize(renderWindow, textures, transition);
	gui::ComponentsBuilder::SetFont(&font);

	// Controllers
	controllers.Add(new ctrl::LocationController);
	controllers.Add(new ctrl::FaxController);
	controllers.Add(new ctrl::NotebookController);
	controllers.Add(new ctrl::MapController);
	controllers.Add(new ctrl::IngameMenuController);
	controllers.Add(new ctrl::LeftSideMenuController);
	controllers.Add(new ctrl::DebugController);
	controllers.Add(new ctrl::TurnsController);
	controllers.Add(new ctrl::DateController);
	controllers.Add(new ctrl::GameController);
	controllers.Add(new ctrl::TriggersController);
	cout << "Game loaded" << endl;

	ctrl::Controller::SortDrawablesList();
}

void GameState::OnLeave()
{
	cout << "Game unloaded" << endl;
}

void GameState::OnUpdate(sf::Time elapsedTimes)
{
	controllers.Update(elapsedTimes);
}

void GameState::OnHandleEvent(sf::Event event)
{
	controllers.HandleEvent(event);
}

void GameState::OnDraw()
{
	controllers.Draw();
}
