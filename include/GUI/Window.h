#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "GUI/UIComposite.h"
#include "GUI/GraphicComponent.h"

namespace gui {

	class Window : public gui::UIComposite{
	public:
		void SetBackground(std::shared_ptr<gui::GraphicComponent> background);
		std::shared_ptr<gui::GraphicComponent> GetBackground();
		sf::FloatRect GetWindowArea();

	private:
		std::shared_ptr<gui::GraphicComponent> background;

	protected:
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const; 
		virtual void OnSetPosition(sf::Vector2f position) override;
	};
}

#endif // !GUI_WINDOW_H
