#ifndef GUI_UI_COMPONENT_H
#define GUI_UI_COMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "GUI/CompoundEventBehavior.h"
#include <memory>

namespace gui {

	class UIComponent : public sf::Drawable, public gui::UIObject{
		sf::Vector2f position;
		gui::CompoundEventBehavior eventBehaviors;
	public: 
		void SetPosition(sf::Vector2f position);
		sf::Vector2f GetPosition();
		virtual void Update() {}
		void HandleEvent(const sf::Event&);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	protected:
		virtual void OnSetPosition(sf::Vector2f position) {}
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const {}
		virtual bool CheckEventCondition(const sf::Event& event) { return true; }
		gui::CompoundEventBehavior& GetEventBehaviors();
	};

}

#endif // !GUI_UI_COMPONENT_H