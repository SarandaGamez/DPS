#ifndef CTRL_LOCATION_CONTROLLER_H
#define CTRL_LOCATION_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/GraphicComponent.h"

namespace ctrl {
	class LocationController : public ctrl::Controller {
	public:
		LocationController();
		~LocationController();

		virtual void Update(sf::Time time) override;
		virtual void HandleEvent(sf::Event event) override;
		virtual void Draw() const override;
	private:
	};
}

#endif // !CTRL_LOCATION_CONTROLLER_H