#include "Controllers/NotebookController.h"
#include "GUI/GraphicComponent.h"
#include "GUI/Window.h"
#include "GUI/ComponentsBuilder.h"
#include "GUI/Notebook.h"
#include "Utils/StringUtils.h"
#include "GUI/ButtonsBuilder.h"

ctrl::NotebookController::NotebookController()
{
	// Load assets
	textures->Load("Notebook", "assets/graphics/GUI/Notebook.png");
	textures->Load("ArrowLeft", "assets/graphics/GUI/ArrowLeft.png");
	textures->Load("ArrowRight", "assets/graphics/GUI/ArrowRight.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");

	// Initialize tools
	gui::ButtonsBuilder buttonsBuilder;

	// Notebook button
	button = buttonsBuilder.BuildClickableRegion({ 850, 875, 210, 75 });
	button->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		if (currentLayer == 0 && notebook->GetWindow()->IsActive() == false)
			notebook->GetWindow()->SetActive(true);
		currentLayer = 1;
		});

	// Notebook background
	auto notebookBgr = std::shared_ptr<gui::GraphicComponent>(new gui::GraphicComponent(textures->GetTexture("Notebook")));
	notebookBgr->GetSprite().setScale(2.f, 1.75f);

	// Notebook text pages
	auto firstPage = gui::ComponentsBuilder::BuildTextComponent(20, { 80, 185 });
	auto secondPage = gui::ComponentsBuilder::BuildTextComponent(20, { 850, 125 });

	// Notebook compound window
	notebookWindow = std::shared_ptr<gui::Window>(new gui::Window());
	notebookWindow->SetBackground(notebookBgr);
	notebookWindow->SetLayer(1);

	notebook = std::shared_ptr<gui::Notebook>(new gui::Notebook(notebookWindow, firstPage, secondPage));
	std::string noteTexts[4];
	noteTexts[0] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas porta aliquet lobortis. Vivamus molestie purus in tellus tincidunt efficitur. Donec vitae tellus augue. Nunc scelerisque bibendum arcu, a feugiat libero accumsan porttitor. Phasellus ut purus ac felis dignissim vulputate eu nec metus. Vestibulum sit amet odio aliquet, ultricies lorem ut, laoreet quam. Aenean tempus pretium lacus et suscipit. Vivamus justo tellus, tempor id velit non, convallis pulvinar erat. Maecenas pellentesque sem at neque porta, sed porttitor enim laoreet. Nulla eget odio et risus hendrerit sollicitudin a vitae nisi.";
	noteTexts[1] = "Quisque malesuada et velit ac placerat. Morbi ut lorem quis ex tincidunt viverra ut nec leo. Cras interdum libero vitae eros sodales porta rutrum tincidunt diam. Maecenas a ex eget orci lobortis pulvinar. Curabitur interdum, ipsum vitae accumsan pellentesque, sem erat lacinia dui, ac lacinia urna urna tincidunt ligula. Vivamus vel lobortis ex, eget ullamcorper neque. Praesent nibh ligula, consequat elementum facilisis at, interdum vitae mi. Quisque eu feugiat magna. Pellentesque condimentum tellus quis ante elementum porttitor. Aliquam erat volutpat. Cras imperdiet massa in viverra egestas. Etiam sit amet feugiat felis. Duis eget tellus et odio varius aliquam et ullamcorper elit. Ut imperdiet tortor quis ante porta fringilla. Vestibulum lacinia ex nunc, ac tincidunt neque rhoncus a.";
	noteTexts[2] = "Phasellus a risus ut est posuere malesuada. Sed congue dignissim sem, sit amet luctus nibh porta ut. Mauris porttitor ante enim, id sodales massa varius a. Fusce vulputate tellus quis varius blandit. Phasellus ac mollis velit. Nulla bibendum vehicula mollis. Fusce sit amet dictum massa. Vestibulum gravida efficitur neque in cursus. Proin placerat, sem sed facilisis ornare, arcu velit cursus arcu, id volutpat purus neque sed sem. Vivamus justo tellus, tempor id velit non, convallis pulvinar erat. Maecenas pellentesque sem at neque porta, sed porttitor enim laoreet. Nulla eget odio et risus hendrerit sollicitudin a vitae nisi.";
	noteTexts[3] = "Mauris sed elementum felis. Nullam magna velit, dapibus vitae consectetur non, lacinia sed augue. Donec in leo non ante tempus aliquam. Phasellus odio libero, tempor quis aliquet fringilla, ultricies eu diam. Morbi in placerat arcu. Praesent id nisi et est consectetur varius. Nulla at arcu eu felis euismod tincidunt. Proin sit amet libero eget sem blandit congue. Mauris eget ornare nisl. Duis dignissim, orci non varius consequat, lectus ex ultricies risus, tempus porttitor libero turpis nec libero. Maecenas augue neque, faucibus condimentum tortor quis, feugiat venenatis quam. Sed pretium sem arcu, sed fermentum nisi porttitor in. Nam laoreet, augue quis aliquam placerat, lacus dolor pellentesque libero, vel molestie enim lectus sit amet nulla. Cras vel condimentum mauris.";
	for (auto text : noteTexts)
		notebook->AddText(utils::StringUtils::BreakLines(text, 22));

	auto notebookSize = notebookWindow->GetWindowArea();
	leftArrow = std::shared_ptr<gui::Button>(new gui::Button(textures->GetTexture("ArrowLeft"), { -128, notebookSize.height - 200 }));
	rightArrow = std::shared_ptr<gui::Button>(new gui::Button(textures->GetTexture("ArrowRight"), { notebookSize.width, notebookSize.height - 200 }));
	notebookWindow->Add(leftArrow)
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		notebook->PreviousPage();
			});
	notebookWindow->Add(rightArrow)
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		notebook->NextPage();
			});


	notebookWindow->SetPosition({ renderWindow->getSize().x / 2 - notebookWindow->GetWindowArea().width / 2, renderWindow->getSize().y / 2 - notebookWindow->GetWindowArea().height / 2 });
	notebookWindow->SetActive(false);

	actions.Push(new game::Action([=]() {
		notebook->GetWindow()->SetActive(true);
		currentLayer = 1;
		actions.Wait(1000);
		}));
	actions.Push(new game::Action([=]() {
		notebook->GetWindow()->SetActive(false);
		actions.Wait(500);
		}));
	actions.Push(new game::Action([=]() {
		signals.Emit("FAX_SHOW_PAPER");
		}));

	waitingTime = sf::Time::Zero;
}

ctrl::NotebookController::~NotebookController()
{
}

void ctrl::NotebookController::Update(sf::Time time)
{
	notebookWindow->Update(time);
	if (notebookWindow->IsActive() == true && notebookWindow->IsVisible() == false)
		notebookWindow->SetVisible(true);
	else if (notebookWindow->IsActive() == false && notebookWindow->IsVisible() == true) {
		notebookWindow->SetVisible(false);
		currentLayer = 0;
	}
}

void ctrl::NotebookController::HandleEvent(sf::Event event)
{
	sf::Vector2f mousePosition = { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };

	if (currentLayer == 0)
		button->HandleEvent(event);

	if (currentLayer == 1)
		notebookWindow->HandleEvent(event);

	// Close notebook after clicking outside of it
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		if (!notebookWindow->GetWindowArea().contains(mousePosition) && !leftArrow->GetRegion().contains(mousePosition) && !rightArrow->GetRegion().contains(mousePosition))
			notebookWindow->SetActive(false);
	}
	// Close notebook with escape
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape && currentLayer > 0 && notebookWindow->IsActive()) {
			notebookWindow->SetActive(false);
		}
	}
}

void ctrl::NotebookController::Draw() const
{
	renderWindow->draw(*notebookWindow);
	if (notebookWindow->IsVisible()) {
		renderWindow->draw(*leftArrow);
		renderWindow->draw(*rightArrow);
	}
}