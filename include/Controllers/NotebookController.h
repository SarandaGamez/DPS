#ifndef CONTROLLER_NOTEBOOK_CONTROLLER_H
#define CONTROLLER_NOTEBOOK_CONTROLLER_H

#include "GUI/Window.h"
#include "GUI/TextComponent.h"
#include <memory>
#include <vector>

namespace controllers {

	class Notebook{
	public:
		Notebook(std::shared_ptr<gui::Window> window, std::shared_ptr<gui::TextComponent> firstPage, std::shared_ptr<gui::TextComponent> secondPage);
		void NextPage();
		void PreviousPage();
		void AddText(const std::string& text);
		std::shared_ptr<gui::Window> GetWindow();
	private:
		void ChangePage();

		unsigned int theLastPage = 0;
		unsigned int currentPage = 0;
		std::vector<std::string> texts;
		std::shared_ptr<gui::TextComponent> firstPage;
		std::shared_ptr<gui::TextComponent> secondPage;
		std::shared_ptr<gui::Window> window;

	};
}

#endif // NOTEBOOK_CONTROLLER_H