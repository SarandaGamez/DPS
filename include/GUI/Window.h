#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "GUI/CompoundUIComponents.h"
#include "GUI/GraphicComponent.h"

namespace gui {

	class Window : public gui::CompoundUIComponents{
	public:
		void SetBackground(std::shared_ptr<gui::GraphicComponent> background);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		std::shared_ptr<gui::GraphicComponent> background;
	};
}

#endif // !GUI_WINDOW_H
