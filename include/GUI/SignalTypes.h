#ifndef GUI_SIGNAL_TYPES_H
#define GUI_SIGNAL_TYPES_H

#include "Utils/Signal.h"

namespace gui {

	class SignalTypes {
	public:
		static utils::Signal::GUID onLeftMouseButtonPressed;
		static utils::Signal::GUID onLeftMouseButtonReleased;
		static utils::Signal::GUID onRightMouseButtonPressed;
		static utils::Signal::GUID onRightMouseButtonReleased;
		static utils::Signal::GUID onMouseEnter;
		static utils::Signal::GUID onMouseLeave;
	};

	utils::Signal::GUID onLeftMouseButtonPressed = 0;
	utils::Signal::GUID onLeftMouseButtonReleased = 0;
	utils::Signal::GUID onRightMouseButtonPressed = 0;
	utils::Signal::GUID onRightMouseButtonReleased = 0;
	utils::Signal::GUID onMouseEnter = 0;
	utils::Signal::GUID onMouseLeave = 0;
}

#endif // !GUI_SIGNAL_TYPES_H
