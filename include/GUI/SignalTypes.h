#ifndef GUI_SIGNAL_TYPES_H
#define GUI_SIGNAL_TYPES_H

#include "Utils/Signal.h"

namespace gui {
	struct SignalTypes {
		static utils::Signal::GUID onLeftMouseButtonPressed;
		static utils::Signal::GUID onLeftMouseButtonReleased;
		static utils::Signal::GUID onRightMouseButtonPressed;
		static utils::Signal::GUID onRightMouseButtonReleased;
		static utils::Signal::GUID onMouseEnter;
		static utils::Signal::GUID onMouseLeave;
	};
}

#endif // !GUI_SIGNAL_TYPES_H
