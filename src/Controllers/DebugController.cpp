#include "Controllers/DebugController.h"
#include "GUI/ComponentsBuilder.h"
#include <sstream>
#include <iomanip>

ctrl::DebugController::DebugController()
{
	font.loadFromFile("assets/fonts/cinematic.ttf");
	gui::ComponentsBuilder componentsBuilder;
	debugText = componentsBuilder.BuildTextComponent(font, 20, { 20,20 }, "");
}

ctrl::DebugController::~DebugController()
{
}

void ctrl::DebugController::Update(sf::Time time)
{
	if(isWindowClosed)
		renderWindow->close();

	auto mousePos = renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*renderWindow));
	std::stringstream ss;
	ss << std::fixed << std::setprecision(0) << mousePos.x << ":" << mousePos.y;
	debugText->SetText(ss.str());
}

void ctrl::DebugController::HandleEvent(sf::Event event)
{
}

void ctrl::DebugController::Draw() const
{
	renderWindow->draw(*debugText);
}
