#ifndef GUI_UI_STATE_H
#define GUI_UI_STATE_H

#include "GUI/UIObject.h"

namespace gui {

	class UIState : public gui::UIObject {
		
	public:
		void SetActive(bool isActive);
		void SetVisible(bool isVisible);
		bool IsActive() const;
		bool IsVisible() const;

	private:
		bool isVisible = true;
		bool isActive = true;
	};
}

#endif // !GUI_UI_STATE_H