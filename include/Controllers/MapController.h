#ifndef CTRL_MAP_CONTROLLER_H
#define CTRL_MAP_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/Button.h"
#include "GUI/Window.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include <vector>

namespace ctrl {
	class MapController : public ctrl::Controller {
	public:
		MapController();
		~MapController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		sf::Texture mapWindowTexture;
		std::shared_ptr<gui::Window> mapWindow;
		std::shared_ptr<gui::ClickableComponent> openMapButton;
		sf::Font font;
	};
}

#endif // ! CTRL_MAP_CONTROLLER_H