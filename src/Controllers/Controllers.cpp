#include "Controllers/Controllers.h"

void ctrl::Controllers::Add(ctrl::Controller* controller)
{
	controllers.push_back(std::shared_ptr<ctrl::Controller>(controller));
}

void ctrl::Controllers::HandleEvent(sf::Event event)
{
	if (!controllers.empty())
		for (auto& contr : controllers)
			contr->HandleEvent(event);
}

void ctrl::Controllers::Update(sf::Time elapsedTimes)
{
	if (!controllers.empty())
		for (auto& contr : controllers)
			contr->Update(elapsedTimes);
}

void ctrl::Controllers::Draw()
{

	for (auto uicomp : drawablesList) {
		renderWindow->draw(*uicomp);
	}

	if (!controllers.empty())
		for (auto& contr : controllers)
			contr->Draw();
}
