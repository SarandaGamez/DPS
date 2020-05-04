#include "GUI/CompoundEventBehavior.h"

namespace gui {

	void CompoundEventBehavior::HandleEvent(const sf::Event& event)
	{
		if (children.empty())
			return;

		for (auto behavior : children) {
			behavior->HandleEvent(event);
		}
	}

	void gui::CompoundEventBehavior::Add(std::shared_ptr<EventBehavior> eventBehavior)
	{
		children.push_back(eventBehavior);
	}

	void gui::CompoundEventBehavior::Remove(std::shared_ptr<EventBehavior> eventBehavior)
	{
		children.remove(eventBehavior);
	}

	std::list<std::shared_ptr<EventBehavior>> gui::CompoundEventBehavior::GetChildren()
	{
		return children;
	}
}
