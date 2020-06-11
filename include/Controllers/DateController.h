#ifndef CTRL_DATE_CONTROLLER_H
#define CTRL_DATE_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/TextComponent.h"
#include <memory>

namespace ctrl {
	class DateController : public ctrl::Controller {
	public:
		DateController();
		~DateController();
		virtual void Update(sf::Time elapsedTime) override;
		virtual void HandleEvent(sf::Event event) override;
		virtual void Draw() const override;
	private:
		std::shared_ptr<gui::TextComponent> turnText;
		std::shared_ptr<gui::TextComponent> dayTimeText;
		unsigned int turnNumber;
		unsigned short dayTime;
		sf::Font font;

	};
}

#endif // !CTRL_DATE_CONTROLLER_H
