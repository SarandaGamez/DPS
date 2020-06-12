#include "Controllers/TurnsController.h"
#include "GUI/ButtonsBuilder.h"
#include "GUI/EventBehavior/SignalTypes.h"

ctrl::TurnsController::TurnsController()
{
	font.loadFromFile("assets/fonts/cinematic.ttf");

	gui::ButtonsBuilder buttonsBuilder;
	buttonsBuilder.SetFont(font);
	buttonsBuilder.SetTexture(textures->GetTexture("Button"));

	sf::Vector2f windowSize = { (float)renderWindow->getSize().x, (float)renderWindow->getSize().y };

	nextTurnButton = std::shared_ptr<gui::TextButton>(buttonsBuilder.BuildTextButton("Next turn", { windowSize.x - textures->GetTexture("Button").getSize().x, windowSize.y - textures->GetTexture("Button").getSize().y }));
	nextTurnButton->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect([=]() {
		NextTurn();
		});

	actions.SetReadyForNext(true);
}

ctrl::TurnsController::~TurnsController()
{
}

void ctrl::TurnsController::Update(sf::Time time)
{
	nextTurnButton->Update(time);

	if (actions.IsReadyForNext() == true && actions.IsWaiting() == false){
		if (actions.IsEmpty() == false) {
			actions.ExecuteAndPop();
		}
		else {
			actions.SetReadyForNext(false);
		}
	}
	actions.UpdateElapsedTime(time);
}

void ctrl::TurnsController::HandleEvent(sf::Event event)
{
	if (currentLayer == 0)
	nextTurnButton->HandleEvent(event);
}

void ctrl::TurnsController::Draw() const
{
	if (currentLayer == 0)
	renderWindow->draw(*nextTurnButton);
}

void ctrl::TurnsController::NextTurn()
{
}
