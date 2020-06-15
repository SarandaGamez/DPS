#ifndef CTRL_TRIGGERS_CONTROLLER_H
#define CTRL_TRIGGERS_CONTROLLER_H

#include "Controllers/Controller.h"
#include "Scripts/Interpreter.h"
#include "Scripts/Trigger.h"
#include "Utils/ConditionSignalsContainer.h"
#include <vector>
#include <memory>

namespace ctrl {
	class TriggersController : public ctrl::Controller {
	public:
		TriggersController();

		virtual void Update(sf::Time elapsedTime) override;
		virtual void HandleEvent(sf::Event event) override;

	private:
		scripts::Interpreter interpreter;
		std::vector<std::shared_ptr<scripts::Trigger>>* triggers;

		void AddAction(const std::string& actionName);
		void AddConditionAction(std::shared_ptr<scripts::Trigger> trigger, const std::string& actionName);
	};
}

#endif // !CTRL_TRIGGERS_CONTROLLER_H
