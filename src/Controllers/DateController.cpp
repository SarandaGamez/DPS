#include "Controllers/DateController.h"
#include "GUI/ComponentsBuilder.h"

ctrl::DateController::DateController()
{
	font.loadFromFile("assets/fonts/cinematic.ttf");

	turnNumber = 1;
	dayTime = 8;

	dayTimeText = std::shared_ptr<gui::TextComponent>(gui::ComponentsBuilder::BuildTextComponent(font, 30, {renderWindow->getSize().x - 775.f, renderWindow->getSize().y - 30.f }, std::to_string(dayTime)));
	turnText = std::shared_ptr<gui::TextComponent>(gui::ComponentsBuilder::BuildTextComponent(font, 30, { renderWindow->getSize().x - 425.f, renderWindow->getSize().y - 30.f}, std::to_string(turnNumber)));

	signals["DATE_NEXT_TURN"].Connect([=]() {
		++turnNumber;
		turnText->SetText("Turn: " + std::to_string(turnNumber));
		});
	signals["DATE_NEXT_HOUR"].Connect([=]() {
		if (dayTime >= 15) {
			dayTime = 8;
			signals.Emit("DATE_NEXT_TURN");
		}
		else {
			dayTime += 1;
		}
		dayTimeText->SetText("Hour: " + std::to_string(dayTime)  + ":00");
		});

	signals.Emit("DATE_NEXT_TURN");
	signals.Emit("DATE_NEXT_HOUR");
	signals.Emit("DATE_NEXT_HOUR");
	signals.Emit("DATE_NEXT_HOUR");
	signals.Emit("DATE_NEXT_HOUR");

}

ctrl::DateController::~DateController()
{
}

void ctrl::DateController::Update(sf::Time elapsedTime)
{

}

void ctrl::DateController::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		// Close Report with escape
		if (event.key.code == sf::Keyboard::D && currentLayer == 0) {
			signals.Emit("DATE_NEXT_HOUR");
		}
	}
}

void ctrl::DateController::Draw() const
{
	if (currentLayer == 0) {
		renderWindow->draw(*dayTimeText);
		renderWindow->draw(*turnText);
	}
}
