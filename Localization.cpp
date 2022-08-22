//
//  Localization.cpp
//  Race_simulator
//
//  Created by Den Fedorov on 08.08.2022.
//
#include <iostream>
#include "Localization.hpp"

void Localization::greeting() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "Welcome to race simulator! Please pick race type ('X' to end or 'C' to change language):\n\n";
	}
	else
	{
		std::cout << "Добро пожаловать в гоночный симулятор! Выберите тип гонки ('X' чтобы выйти, 'C' сменить язык):\n\n";
	}
}

void Localization::menu() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "1. Race for land units.\n";
		std::cout << "2. Race for air units.\n";
		std::cout << "3. Race for air and land units.\n\n";
		std::cout << "Input: ";
	}
	else
	{
		std::cout << "1. Гонка для наземного транспорта.\n";
		std::cout << "2. Гонка для воздушного транспорта.\n";
		std::cout << "3. Гонка для наземного и воздушного транспорта.\n\n";
		std::cout << "Ввод: ";
	}
}

void Localization::get_distance() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "Enter distance length: ";
	}
	else
	{
		std::cout << "Введите длину дистанции: ";
	}
}

void Localization::selected_units(const std::vector<units_ABC *> & ptrs, int n, float d) const
{
	if (m_lang == Lang::eng)
	{
		std::cout << (n == 1 ? "Race for land units. " : n == 2 ? "Race for air units. " : "Race for air and land units. ");
		std::cout << "Distance: " << d << '\n';

		if (ptrs.empty())
		{
			std::cout << "No units registered yet.\n";
		}
		else
		{
			std::cout << "Registered units:\n\n";
		}
	}
	else
	{
		std::cout << (n == 1 ? "Гонка для наземного транспорта. " : n == 2 ? "Гонка для воздушного транспорта. "
					  : "Гонка для наземного и воздушного транспорта. ");
		std::cout << "Дистанция: " << d << '\n';

		if (ptrs.size() == 0)
		{
			std::cout << "Нет зарегистрированного транспорта.\n";
		}
		else
		{
			std::cout << "Зарегистрированный траспорт:\n\n";
		}
	}

	for (size_t i = 0; i < ptrs.size(); ++i)
	{
		std::cout << i + 1 << ": " << ptrs.at(i)->get_name() << '\n';
	}

	std::cout << std::endl;
}

void Localization::units_list(std::vector<units_ABC *> & ptrs, size_t index) const
{
	if (!(ptrs.empty()) && index != 0)
	{
		auto it = ptrs.begin();
		ptrs.erase(it + index - 1);
	}

	if (ptrs.empty())
	{
		std::cout << (m_lang == Lang::eng ? "All units added!" : "Весь транспорт добавлен!");
	}
	else
	{
		for (size_t i = 0; i < ptrs.size(); ++i)
		{
			std::cout << i + 1 << ": " << ptrs.at(i)->get_name() << '\n';
		}
	}

	std::cout << std::endl;

	if (m_lang == Lang::eng)
	{
		std::cout << "Pick a unit ('A' to add all, 'X' to end registration): ";
	}
	else
	{
		std::cout << "Выберите транспорт ('A' добавить всё, 'X' закончить регистрацию): ";
	}
}
void Localization::out_of_range() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "There is no such unit! Repeat: ";
	}
	else
	{
		std::cout << "Такого траспорта не существует! Повторите: ";
	}
}

void Localization::wrong_input() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "Wrong input! Repeat: ";
	}
	else
	{
		std::cout << "Неправильный ввод! Повторите: ";
	}
}

void Localization::race_warning() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "There mush be at least two units registered!\n";
	}
	else
	{
		std::cout << "Должно быть зарегистрировано как минимум два транспорта!\n";
	}
}

void Localization::race_result(const std::vector<units_ABC *> & ptrs) const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "The winner is: " << ptrs.at(0)->get_name();
		std::cout << " with score " << ptrs.at(0)->get_result() << "!\n";
		std::cout << "The loosers are:\n\n";
	}
	else
	{
		std::cout << "Победитель: " << ptrs.at(0)->get_name();
		std::cout << " со счётом " << ptrs.at(0)->get_result() << "!\n";
		std::cout << "Проигравшие:\n\n";
	}

	for (size_t i = 1; i < ptrs.size(); ++i)
	{
		std::cout << i + 1 << ": " << ptrs.at(i)->get_name() << " " << ptrs.at(i)->get_result() << '\n';
	}
}

void Localization::ask_restart() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "Press 'R' to restart or 'X' to exit: ";
	}
	else
	{
		std::cout << "Нажмите 'R' чтобы перезапустить или 'X' чтобы выйти: ";
	}
}

void Localization::farewell() const
{
	if (m_lang == Lang::eng)
	{
		std::cout << "Bye!\n";
	}
	else
	{
		std::cout << "Пока!\n";
	}
}

void Localization::change_language()
{
	m_lang == Lang::eng ? m_lang = Lang::rus : m_lang = Lang::eng;
}

const Localization::Lang & Localization::get_lang() const
{
	return m_lang;
}

Localization::Localization(Lang lang)
{
	m_lang = lang;
}

Localization::~Localization()
{
}