#ifndef GUI_COMPOUND_UI_COMPONENTS_H
#define GUI_COMPOUND_UI_COMPONENTS_H

#include "GUI/UIComponent.h"
#include <list>
#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

namespace gui {
	class UIComposite : public gui::UIComponent{
	public:
		std::shared_ptr<gui::UIComponent> Add(std::shared_ptr<gui::UIComponent> component);
		void Remove(std::shared_ptr<gui::UIComponent> component);
		const std::list<std::shared_ptr<gui::UIComponent>>& GetComponents();
		void Update();
		void HandleEvent(const sf::Event& event);

	private:
		sf::Vector2f compositePosition = { 0,0 };
		std::list <std::shared_ptr<gui::UIComponent>> children;
		
	protected:
		void OnSetPosition(sf::Vector2f position) override;
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif // !GUI_COMPOUND_UI_COMPONENTS_H
