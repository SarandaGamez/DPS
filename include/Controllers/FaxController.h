#ifndef CTRL_FAX_CONTROLLER_H
#define CTRL_FAX_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/Button.h"
#include "GUI/Window.h"
#include <memory>

namespace ctrl {
	class FaxController : public ctrl::Controller {
	public:
		FaxController();
		~FaxController();
		virtual void Update(sf::Time elapsedTime) override;
		virtual void HandleEvent(sf::Event event) override;
		virtual void Draw() const override;
	private:
		std::shared_ptr<gui::Button> reportButton;
		std::shared_ptr<gui::Window> reportWindow;
		sf::Texture paperTexture;
		sf::Texture windowTexture;

	};
}

#endif // !CTRL_FAX_CONTROLLER_H
