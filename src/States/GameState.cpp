#include "States/GameState.h"
#include "States/OverState.h"
#include "StatesMachine.h"
#include "GUI/DialogWindowBuilder.h"
#include "GUI/ButtonsBuilder.h"
#include "GUI/ComponentsBuilder.h"
#include "Controllers/NotebookController.h"
#include "Controllers/DebugController.h"
#include "Controllers/IngameMenuController.h"
#include "Controllers/LeftSideMenuController.h"
#include "Controllers/TurnsController.h"
#include "Controllers/FaxController.h"
#include "Controllers/DateController.h"
#include "Controllers/MapController.h"
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
	gui::ButtonsBuilder buttonsBuilder;

	auto clickable = buttonsBuilder.BuildClickableRegion({ 1230, 790, 190, 90});
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenDialog, this));
	AddUIComponent(clickable);

	clickable = buttonsBuilder.BuildClickableRegion({ 1525, 800, 100, 90 });
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenDialog, this));
	AddUIComponent(clickable);


	background.setTexture(textures.GetTexture("OfficeBackground"));

	auto windowBgr = std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures.GetTexture("Window")));

	gui::DialogWindowBuilder dialogWindowBuilder(std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures.GetTexture("DialogWindow"))));
	dialogWindowBuilder.SetCaption("Feature is not available at the moment", font);
	dialogWindowBuilder.AddOption("Close", font, textures.GetTexture("Button"))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::CloseDialog, this));
	dialogWindow = dialogWindowBuilder.GetResult();
	dialogWindow->SetPosition({renderWindow->getSize().x / 2 - dialogWindow->GetWindowArea().width / 2, renderWindow->getSize().y / 2 - dialogWindow->GetWindowArea().height / 2 });
	dialogWindow->SetLayer(1);
	components.push_back(dialogWindow);
	CloseDialog();

	// Controllers
	controllers.Add(new ctrl::FaxController);
	controllers.Add(new ctrl::NotebookController);
	controllers.Add(new ctrl::MapController);
	controllers.Add(new ctrl::IngameMenuController);
	controllers.Add(new ctrl::LeftSideMenuController);
	controllers.Add(new ctrl::DebugController);
	controllers.Add(new ctrl::TurnsController);
	controllers.Add(new ctrl::DateController);


	cout << "Game loaded" << endl;
}

void GameState::OnLeave()
{
	cout << "Game unloaded" << endl;
}

void GameState::OpenDialog()
{
	cout << "TEST" << endl;
	dialogWindow->SetVisible(true);
	dialogWindow->SetActive(true);
	this->currentLayer = 1;
}

void GameState::CloseDialog()
{
	cout << "TEST2" << endl;
	dialogWindow->SetVisible(false);
	dialogWindow->SetActive(false);
	this->currentLayer = 0;
}

void GameState::AddUIComponent(std::shared_ptr<gui::UIComponent> component)
{
	compositeBuilder.Reset();
	compositeBuilder.Add(component);
	components.push_back(compositeBuilder.GetResult());
}

void GameState::OnUpdate(sf::Time elapsedTimes)
{
	if(!components.empty())
	for (auto &comp : components)
		if(comp->GetLayer() == currentLayer)
			comp->Update(elapsedTimes);
	controllers.Update(elapsedTimes);
}

void GameState::OnHandleEvent(sf::Event event)
{
	if (!components.empty())
	for (auto &comp : components)
		if (comp->GetLayer() == currentLayer)
			comp->HandleEvent(event);
	controllers.HandleEvent(event);
}

void GameState::OnDraw()
{
	renderWindow->draw(background);

	if (!components.empty())
	for (auto &comp : components)
		if (comp->GetLayer() == currentLayer)
			renderWindow->draw(*comp);

	controllers.Draw();
}
