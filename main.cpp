//
//  main.cpp
//  Race_simulator_v2
//
//  Created by Den Fedo	rov on 19.08.2022.
//

#include <memory>
#include <algorithm>
#include "Keyboard.h"
#include "Display.h"
#include "Units_ABC.h"
#include "Camel.h"
#include "Fast_camel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Magic_carpet.h"
#include "Eagle.h"
#include "Magic_broom.h"

#if defined (_WIN32)
#include <Windows.h>
#endif

#define ptr std::unique_ptr<rs::Units_ABC>
#define ENG d.get_lang() == rs::Lang::ENG

void clear()
{
#if defined(_WIN32)
	system("cls");
	SetConsoleOutputCP(65001);
#else
	system("clear");
#endif
}

auto add_new_unit(int index, const rs::Display & d) -> ptr
{
	switch (index)
	{
		case 0:
		{
			return (ptr(new rs::Camel(ENG ? "Camel" : "Верблюд")));
		}
		case 1:
		{
			return (ptr(new rs::Fast_camel(ENG ? "Fast_camel" : "Верблюд-быстроход")));
		}
		case 2:
		{
			return (ptr(new rs::Centaur(ENG ? "Centaur" : "Кентавр")));
		}
		case 3:
		{
			return (ptr(new rs::All_terrain_boots(ENG ? "All terrain boots" : "Ботинки-вездеходы")));
		}
		case 4:
		{
			return (ptr(new rs::Magic_carpet(ENG ? "Magic carpet" : "Ковёр-самолёт")));
		}
		case 5:
		{
			return (ptr(new rs::Eagle(ENG ? "Eagle" : "Орёл")));
		}
		case 6:
		{
			return (ptr(new rs::Magic_broom(ENG ? "Magic broom" : "Метла")));
		}
		default:
		{
			return nullptr;
		}
	}
}

auto main() -> int
{
#if defined (_WIN32)
//	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(65001);
#else
	clear();
#endif

	char ch = '0';
	rs::Display d;
	rs::Check<char, 7> main_menu{ '1', '2', '3', 'c', 'C', 'x', 'X' };
	std::vector<std::unique_ptr<rs::Units_ABC>> units;

	while (ch != 'x' && ch != 'X')
	{
		d.greetings();
		d.main_menu();
		std::cin >> ch;
		std::cin.ignore(10000, '\n');

		switch (main_menu.find(ch))
		{
			case '1':
			{
				d.set_mode(rs::Mode::LAND);

				for (int i = 0; i < 4; ++i)
				{
					units.push_back(add_new_unit(i, d));
				}

				break;
			}
			case '2':
			{
				d.set_mode(rs::Mode::AIR);

				for (int i = 4; i < 7; ++i)
				{
					units.push_back(add_new_unit(i, d));
				}

				break;
			}
			case '3':
			{
				d.set_mode(rs::Mode::ALL);

				for (int i = 0; i < 7; ++i)
				{
					units.push_back(add_new_unit(i, d));
				}

				break;
			}
			case 'c':
			case 'C':
			{
				clear();
				d.set_locale();
				continue;
			}
			case 'x':
			case 'X':
			{
				clear();
				d.farewell();
				exit(EXIT_SUCCESS);
			}
			default:
			{
				clear();
				d.wrong_input();
				continue;
			}
		}

		clear();
		float distance = 0.0f;
		d.distance();

		while (!(std::cin >> distance) || distance <= 0)
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			d.distance();
		}

		clear();
		int index = 0;
		std::vector<std::unique_ptr<rs::Units_ABC>> race_units;
		rs::Check<char, 11> add_menu{ '1', '2', '3', '4', '5', '6', '7', 'a', 'A', 'x', 'X' };

		while (true)
		{
			d.units_menu(units, race_units, distance);
			std::cin >> ch;
			std::cin.ignore(10000, '\n');

			switch (add_menu.find(ch))
			{
				case 'a':
				case 'A':
				{
					clear();

					for (auto i = 0; i < units.size(); ++i)
					{
						race_units.push_back(std::move(units[i]));
					}

					units.clear();
					continue;
				}
				case 'x':
				case 'X':
				{
					clear();

					if (race_units.size() < 2)
					{
						clear();
						d.warning();
						continue;
					}
					else
					{
						break;
					}
				}
				default:
				{
					index = ch - 48;

					if (index > units.size())
					{
						clear();
						d.wrong_input();
						continue;
					}
					else
					{
						clear();
						race_units.push_back(std::move(units[index - 1]));
						units.erase(units.begin() + index - 1);
						continue;
					}
				}

				break;
			}

			break;
		}

		for (int i = 0; i < race_units.size(); ++i)
		{
			race_units[i]->calculation(distance);
		}

		clear();

		auto lambda = [](std::unique_ptr<rs::Units_ABC> & lhs, std::unique_ptr<rs::Units_ABC> & rhs) -> bool
		{
			return lhs->get_result() < rhs->get_result();
		};

		std::sort(std::begin(race_units), std::end(race_units), lambda);
		d.end_menu(race_units);
		rs::Check<char, 4> end_menu{ 'x', 'X', 'r', 'R' };
		std::cin >> ch;
		std::cin.ignore(10000, '\n');

		switch (end_menu.find(ch))
		{
			case 'r':
			case 'R':
			{
				clear();
				race_units.clear();
				continue;
			}
			case 'x':
			case 'X':
			{
				break;
			}
		}
	}

	clear();
	std::cout << "Bye!\n";
	return 0;
}