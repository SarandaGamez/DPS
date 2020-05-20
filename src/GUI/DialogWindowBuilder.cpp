#include "GUI/DialogWindowBuilder.h"

gui::DialogWindowBuilder::DialogWindowBuilder(std::shared_ptr<gui::GraphicComponent> background)
{
	Reset(background);
}

gui::DialogWindowBuilder::DialogWindowBuilder(std::shared_ptr<gui::Window> window)
{
	Reset(window);
}

void gui::DialogWindowBuilder::Reset(std::shared_ptr<gui::Window> window)
{
	this->window = window;
	buttons.clear();
	caption = nullptr;
}

void gui::DialogWindowBuilder::Reset(std::shared_ptr<gui::GraphicComponent> background)
{
	Reset(std::shared_ptr<gui::Window>(new gui::Window));
	window->SetBackground(background);
}

void gui::DialogWindowBuilder::SetCaption(const std::string& caption, const sf::Font& font)
{
	this->caption = std::shared_ptr<gui::TextComponent>(new gui::TextComponent);
	this->caption->SetFont(font);
	this->caption->SetText(caption);
	AlignCaption(caption);
}

std::shared_ptr<gui::TextButton> gui::DialogWindowBuilder::AddOption(const std::string& caption, const sf::Font& font, const sf::Texture& buttonTexture)
{
	auto button = std::shared_ptr<gui::TextButton>(new gui::TextButton(buttonTexture, font, caption, { 0,0 }));
	buttons.push_back(button);
	AlignButtons();

	return button;
}

std::shared_ptr<gui::Window> gui::DialogWindowBuilder::GetResult()
{
	if (caption)
		window->Add(caption);

	if (!buttons.empty())
		for (auto button : buttons)
			window->Add(button);

	auto result = window;
	window = nullptr;
	return result;
}

void gui::DialogWindowBuilder::AlignButtons()
{
	float buttonsWidth = 0;
	for (auto button : buttons)
		buttonsWidth += button->GetRegion().width;
	buttonsWidth /= buttons.size();

	auto firstButtonPos = (window->GetWindowArea().width - (buttonsWidth + 50) * buttons.size() + 50) / 2;

	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->SetPosition({ firstButtonPos + (buttonsWidth + 50) * i, window->GetWindowArea().height / 1.5f });
	}

}

void gui::DialogWindowBuilder::AlignCaption(const std::string& caption)
{
	auto textAreaWidth = this->window->GetWindowArea().width * 0.8f;
	auto textSize = this->caption->GetGlobalBounds();

	if (textSize.width >= textAreaWidth) {
		this->caption->SetCharacterSize(textAreaWidth / caption.length());
	}

	textSize = this->caption->GetGlobalBounds();


	this->caption->SetPosition({ window->GetWindowArea().width / 2 - textSize.width / 2, window->GetWindowArea().height / 4 });
}

