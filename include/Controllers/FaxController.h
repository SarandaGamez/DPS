#ifndef CTRL_FAX_CONTROLLER_H
#define CTRL_FAX_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/Button.h"
#include "GUI/Window.h"
#include "GUI/TextComponent.h"
#include "GUI/AnimatedButton.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
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
		std::shared_ptr<gui::AnimatedButton> reportButton;
		std::shared_ptr<gui::Window> reportWindow;
		std::shared_ptr<gui::TextComponent> reportText;
		sf::Texture paperTexture;
		sf::Texture windowTexture;
		sf::Font font;

	};
}

#endif // !CTRL_FAX_CONTROLLER_H
