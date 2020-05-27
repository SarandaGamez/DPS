#include "Controllers/NotebookController.h"
#include "GUI/GraphicComponent.h"
#include "GUI/Window.h"
#include "GUI/ComponentsBuilder.h"
#include "GUI/Notebook.h"
#include "Utils/StringUtils.h"
#include "GUI/ButtonsBuilder.h"
#include <iostream>

using std::cout;
using std::endl;

ctrl::NotebookController::NotebookController(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& textures, StateTransition* transition) : Controller(renderWindow,textures,transition)
{
	textures.Load("Notebook", "assets/GUI/Office/Notebook.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");

	gui::ButtonsBuilder buttonsBuilder;

	//Notebook button
	button = buttonsBuilder.BuildClickableRegion({ 850, 875, 210, 75 });
	button->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&NotebookController::OpenNotebook, this));

	//Notebook background
	auto notebookBgr = std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures.GetTexture("Notebook")));
	notebookBgr->GetSprite().setScale(0.8f, 0.75f);

	//Notebook text pages
	auto firstPage = gui::ComponentsBuilder::BuildTextComponent(font, 20, { 100 * 0.8f, 250 * 0.75f });
	auto secondPage = gui::ComponentsBuilder::BuildTextComponent(font, 20, { 1025 * 0.8f, 250 * 0.75f });

	//Notebook compound window
	auto notebookWindow = std::shared_ptr<gui::Window>(new gui::Window());
	notebookWindow->SetBackground(notebookBgr);
	notebookWindow->SetLayer(1);

	notebook = std::shared_ptr<gui::Notebook>(new gui::Notebook(notebookWindow, firstPage, secondPage));

	//Prepare test text strings
	std::string noteTexts[4];
	noteTexts[0] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas porta aliquet lobortis. Vivamus molestie purus in tellus tincidunt efficitur. Donec vitae tellus augue. Nunc scelerisque bibendum arcu, a feugiat libero accumsan porttitor. Phasellus ut purus ac felis dignissim vulputate eu nec metus. Vestibulum sit amet odio aliquet, ultricies lorem ut, laoreet quam. Aenean tempus pretium lacus et suscipit. Duis dignissim, orci non varius consequat, lectus ex ultricies risus, tempus porttitor libero turpis nec libero. Maecenas augue neque, faucibus condimentum tortor quis, feugiat venenatis quam. Sed pretium sem arcu, sed fermentum nisi porttitor in. Nam laoreet, augue quis aliquam placerat, lacus dolor pellentesque libero, vel molestie enim lectus sit amet nulla. Cras vel condimentum mauris. Vivamus justo tellus, tempor id velit non, convallis pulvinar erat. Maecenas pellentesque sem at neque porta, sed porttitor enim laoreet. Nulla eget odio et risus hendrerit sollicitudin a vitae nisi.";
	noteTexts[1] = "Quisque malesuada et velit ac placerat. Morbi ut lorem quis ex tincidunt viverra ut nec leo. Cras interdum libero vitae eros sodales porta rutrum tincidunt diam. Maecenas a ex eget orci lobortis pulvinar. Curabitur interdum, ipsum vitae accumsan pellentesque, sem erat lacinia dui, ac lacinia urna urna tincidunt ligula. Vivamus vel lobortis ex, eget ullamcorper neque. Praesent nibh ligula, consequat elementum facilisis at, interdum vitae mi. Quisque eu feugiat magna. Pellentesque condimentum tellus quis ante elementum porttitor. Aliquam erat volutpat. Cras imperdiet massa in viverra egestas. Etiam sit amet feugiat felis. Duis eget tellus et odio varius aliquam et ullamcorper elit. Ut imperdiet tortor quis ante porta fringilla. Vestibulum lacinia ex nunc, ac tincidunt neque rhoncus a.";
	noteTexts[2] = "Phasellus a risus ut est posuere malesuada. Sed congue dignissim sem, sit amet luctus nibh porta ut. Mauris porttitor ante enim, id sodales massa varius a. Fusce vulputate tellus quis varius blandit. Phasellus ac mollis velit. Nulla bibendum vehicula mollis. Fusce sit amet dictum massa. Vestibulum gravida efficitur neque in cursus. Proin placerat, sem sed facilisis ornare, arcu velit cursus arcu, id volutpat purus neque sed sem.";
	noteTexts[3] = "Mauris sed elementum felis. Nullam magna velit, dapibus vitae consectetur non, lacinia sed augue. Donec in leo non ante tempus aliquam. Phasellus odio libero, tempor quis aliquet fringilla, ultricies eu diam. Morbi in placerat arcu. Praesent id nisi et est consectetur varius. Nulla at arcu eu felis euismod tincidunt. Proin sit amet libero eget sem blandit congue. Mauris eget ornare nisl.";
	for (auto text : noteTexts)
		notebook->AddText(utils::StringUtils::BreakLines(text, 25));

	notebookWindow->SetPosition({ renderWindow->getSize().x / 2 - notebookWindow->GetWindowArea().width / 2, renderWindow->getSize().y / 2 - notebookWindow->GetWindowArea().height / 2 });
	CloseNotebook();
}

ctrl::NotebookController::~NotebookController()
{
}

void ctrl::NotebookController::Update(sf::Time time)
{
	this->notebook->GetWindow()->Update();
}

void ctrl::NotebookController::HandleEvent(sf::Event event)
{
	this->notebook->GetWindow()->HandleEvent(event);
	this->button->HandleEvent(event);

	if (event.key.code == sf::Keyboard::Right) {
		if (notebook->GetWindow()->IsActive())
			notebook->NextPage();
	}
	if (event.key.code == sf::Keyboard::Left) {
		if (notebook->GetWindow()->IsActive())
			notebook->PreviousPage();
	}
}

void ctrl::NotebookController::Draw() const
{
	renderWindow->draw(*notebook->GetWindow());
}

void ctrl::NotebookController::OpenNotebook()
{
	cout << "Open Notebook" << endl;
	notebook->GetWindow()->SetVisible(true);
	notebook->GetWindow()->SetActive(true);
	this->currentLayer = 1;
}

void ctrl::NotebookController::CloseNotebook()
{
	cout << "Close Notebook" << endl;
	notebook->GetWindow()->SetVisible(false);
	notebook->GetWindow()->SetActive(false);
	this->currentLayer = 0;
}
