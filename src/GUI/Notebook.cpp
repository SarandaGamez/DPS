#include "GUI/Notebook.h"

gui::Notebook::Notebook(std::shared_ptr<gui::Window> window, std::shared_ptr<gui::TextComponent> firstPage, std::shared_ptr<gui::TextComponent> secondPage)
{
	this->window = window;
	this->firstPage = firstPage;
	this->secondPage = secondPage;
	this->window->Add(firstPage);
	this->window->Add(secondPage);
}

void gui::Notebook::NextPage()
{
	if (currentPage + 2 <= theLastPage) {
		currentPage += 2;
		ChangePage();
	}
}

void gui::Notebook::PreviousPage()
{
	if (currentPage >= 2) {
		currentPage -= 2;
		ChangePage();
	}
}

void gui::Notebook::AddText(const std::string& text)
{
	this->texts.push_back(text);

	if (texts.size() % 2 == 0)
		theLastPage = texts.size() - 2;
	else
		theLastPage = texts.size() - 1;

	ChangePage();
}

std::shared_ptr<gui::Window> gui::Notebook::GetWindow()
{
	return window;
}

void gui::Notebook::ChangePage()
{
	if (texts.size() > 0) {
		firstPage->SetText(texts[currentPage]);
		if (texts.size() > currentPage + 1) {
			secondPage->SetText(texts[currentPage + 1]);
		}
	}
}
