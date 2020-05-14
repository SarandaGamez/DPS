#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "GUI/UIComposite.h"
#include "GUI/GraphicComponent.h"

namespace gui {

	class Window : public gui::UIComposite{
	public:
		void SetBackground(std::shared_ptr<gui::GraphicComponent> background);
		sf::FloatRect GetWindowArea();

	private:
		std::shared_ptr<gui::GraphicComponent> background;

	protected:
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const; 
	};
}

#endif // !GUI_WINDOW_H
