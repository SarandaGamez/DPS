#ifndef GUI_UI_COMPONENT_H
#define GUI_UI_COMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "GUI/EventBehavior/CompoundEventBehavior.h"
#include "Utils/StateObject.h"
#include <memory>

namespace gui {
	class UIComponent : public sf::Drawable, public utils::StateObject{
		sf::Vector2f position;
		gui::CompoundEventBehavior eventBehaviors;
		unsigned short layer = 0;
	public: 
		void SetPosition(sf::Vector2f position);
		sf::Vector2f GetPosition();

		void SetLayer(unsigned short layer);
		unsigned short GetLayer() const;

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