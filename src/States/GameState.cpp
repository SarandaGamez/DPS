#include "States/GameState.h"
#include "States/OverState.h"
#include "StatesMachine.h"
#include "GUI/DialogWindowBuilder.h"
#include "GUI/ButtonsBuilder.h"
#include "GUI/TooltipComponent.h"
#include <string>
#include "Utils/StringUtils.h"

#include <iostream>

using std::cout;
using std::endl;

void GameState::OnEnter()
{
	cout << "Loading textures" << endl;
	textures.Load("OfficeBackground", "assets/GUI/Office/ProsecutorsOffice.png");
	textures.Load("Window", "assets/GUI/Office/Window.png");
	textures.Load("Notebook", "assets/GUI/Office/Notebook.png");
	textures.Load("DialogWindow", "assets/GUI/Office/DialogWindow.png");
	textures.Load("Button", "assets/GUI/MainMenu/Button.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");
	cout << "Loading textures done" << endl;

	gui::ButtonsBuilder buttonsBuilder;

	auto tooltip = std::shared_ptr<gui::TooltipComponent>(new gui::TooltipComponent(textures.GetTexture("Button"), font, "Not Available", { 1250, 400 }));
	tooltip->SetVisible(false);
	AddUIComponent(tooltip);

	auto hoverable = buttonsBuilder.BuildHoverableRegion({ 850, 160, 400, 280 });
	hoverable->GetSignal(gui::SignalTypes::onMouseEnter).Connect( [=]() { tooltip->SetVisible(true); });
	hoverable->GetSignal(gui::SignalTypes::onMouseLeave).Connect([=]() { tooltip->SetVisible(false); });
	AddUIComponent(hoverable);

	auto clickable = buttonsBuilder.BuildClickableRegion({ 850, 160, 400, 280 });
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenDialog, this));
	AddUIComponent(clickable);

	clickable = buttonsBuilder.BuildClickableRegion({ 1230, 790, 190, 90});
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenDialog, this));
	AddUIComponent(clickable);

	clickable = buttonsBuilder.BuildClickableRegion({ 1675, 800, 225, 145 });
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenDialog, this));
	AddUIComponent(clickable);

	clickable = buttonsBuilder.BuildClickableRegion({ 1525, 800, 100, 90 });
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenDialog, this));
	AddUIComponent(clickable);

	//Notebook button
	clickable = buttonsBuilder.BuildClickableRegion({ 850, 875, 210, 75 });
	clickable->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&GameState::OpenNotebook, this));
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

	// Notebook
	auto notebookBgr = std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures.GetTexture("Notebook")));
	notebookBgr->GetSprite().setScale(0.8f, 0.75f);

	std::string noteText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas porta aliquet lobortis. Vivamus molestie purus in tellus tincidunt efficitur. Donec vitae tellus augue. Nunc scelerisque bibendum arcu, a feugiat libero accumsan porttitor. Phasellus ut purus ac felis dignissim vulputate eu nec metus. Vestibulum sit amet odio aliquet, ultricies lorem ut, laoreet quam. Aenean tempus pretium lacus et suscipit. Duis dignissim, orci non varius consequat, lectus ex ultricies risus, tempus porttitor libero turpis nec libero. Maecenas augue neque, faucibus condimentum tortor quis, feugiat venenatis quam. Sed pretium sem arcu, sed fermentum nisi porttitor in. Nam laoreet, augue quis aliquam placerat, lacus dolor pellentesque libero, vel molestie enim lectus sit amet nulla. Cras vel condimentum mauris. Vivamus justo tellus, tempor id velit non, convallis pulvinar erat. Maecenas pellentesque sem at neque porta, sed porttitor enim laoreet. Nulla eget odio et risus hendrerit sollicitudin a vitae nisi.";
	noteText = utils::StringUtils::BreakLines(noteText, 25);

	auto note1 = std::shared_ptr<gui::TextComponent>(new gui::TextComponent());
	note1->SetText(noteText);	
	note1->SetFont(font);
	note1->SetCharacterSize(20);
	note1->SetPosition({ 100 * 0.8f, 250 * 0.75f });
	auto note2 = std::shared_ptr<gui::TextComponent>(new gui::TextComponent());
	note2->SetText(noteText);
	note2->SetFont(font);
	note2->SetCharacterSize(20);
	note2->SetPosition({ 1025 * 0.8f, 250 * 0.75f });

	notebookWindow = std::shared_ptr<gui::Window>(new gui::Window());
	notebookWindow->SetBackground(notebookBgr);
	notebookWindow->Add(note1);
	notebookWindow->Add(note2);
	notebookWindow->SetPosition({ renderWindow->getSize().x / 2 - notebookWindow->GetWindowArea().width / 2, renderWindow->getSize().y / 2 - notebookWindow->GetWindowArea().height / 2 });
	notebookWindow->SetLayer(1);
	components.push_back(notebookWindow);
	CloseNotebook();

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

void GameState::OpenNotebook()
{
	cout << "Open Notebook" << endl;
	notebookWindow->SetVisible(true);
	notebookWindow->SetActive(true);
	this->currentLayer = 1;
}

void GameState::CloseNotebook()
{
	cout << "Close Notebook" << endl;
	notebookWindow->SetVisible(false);
	notebookWindow->SetActive(false);
	this->currentLayer = 0;
}

void GameState::AddUIComponent(std::shared_ptr<gui::UIComponent> component)
{
	compositeBuilder.Reset();
	compositeBuilder.Add(component);
	components.push_back(compositeBuilder.GetResult());
}

void GameState::OnUpdate()
{
	if(!components.empty())
	for (auto &comp : components)
		if(comp->GetLayer() == currentLayer)
			comp->Update();

}

void GameState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;

	if (!components.empty())
	for (auto &comp : components)
		if (comp->GetLayer() == currentLayer)
			comp->HandleEvent(event);
}

void GameState::OnDraw()
{
	renderWindow->draw(background);

	if (!components.empty())
	for (auto &comp : components)
		if (comp->GetLayer() == currentLayer)
			renderWindow->draw(*comp);
}
