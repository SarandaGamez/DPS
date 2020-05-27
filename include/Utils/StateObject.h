#ifndef UTILS_STATE_OBJECT_H
#define UTILS_STATE_OBJECT_H

#include "Utils/SignalObject.h"

namespace utils {
	class StateObject : public utils::SignalObject{
	public:
		void SetActive(bool isActive);
		void SetVisible(bool isVisible);
		void SetMouseInRegion(bool isMouseInRegion);
		bool IsActive() const;
		bool IsVisible() const;
		bool IsMouseInRegion() const;
	private:
		bool isMouseInRegion = false;
		bool isVisible = true;
		bool isActive = true;
	};
}

#endif // UTILS_STATE_OBJECT_H