#ifndef GUI_COMPOUND_UI_COMPONENT_BUILDER_H
#define GUI_COMPOUND_UI_COMPONENT_BUILDER_H

#include "GUI/UIComposite.h"
#include <memory>

namespace gui {

	class UICompositeBuilder {

	public:
		UICompositeBuilder();
		void Reset();
		std::shared_ptr<gui::UIComponent> Add(std::shared_ptr<gui::UIComponent> component);
		virtual std::shared_ptr<gui::UIComposite>& GetResult();

	private:
		std::shared_ptr<gui::UIComposite> composite;
	};
}

#endif // !GUI_COMPOUND_UI_COMPONENT_BUILDER_H
