#include "Display.h"

namespace rs
{
	Display::Display(Lang lng, Mode md) : _lng{lng}, _md{md} { }

	Display::~Display() { }

	auto Display::greetings() const -> void
	{
		std::cout << (ENGLISH ? "Welcome to race simulator!"
					  " Please pick race type ('X' to end or 'C' to change language):\n\n"
					  : "Добро пожаловать в гоночный симулятор!"
					  " Выберите тип гонки ('X' - выход, 'C' - сменить язык):\n\n");
	}

	auto Display::main_menu() const -> void
	{
		std::cout << (ENGLISH ?
					  "1. Race for land units.\n"
					  "2. Race for air units.\n"
					  "3. Race for air and land units.\n\n"
					  "Input: "
					  :
					  "1. Гонка для наземого транспорта.\n"
					  "2. Гонка для воздушного траспорта.\n"
					  "3. Гонка для наземного и воздушного транспорта.\n\n"
					  "Ввод: ");
	}

	auto Display::set_locale() -> void
	{
		ENGLISH ? _lng = Lang::RUS : _lng = Lang::ENG;
	}

	auto Display::set_mode(Mode md) -> void
	{
		_md = md;
	}

	auto Display::get_lang() const -> const Lang &
	{
		return _lng;
	}

	auto Display::wrong_input() const -> void
	{
		std::cout << (ENGLISH ? "Wrong input!\n" : "Неправильный ввод!\n");
	}

	auto Display::distance() const -> void
	{
		std::cout << (ENGLISH ? "Distance length: " : "Длина дистанции: ");
	}

	auto Display::units_menu(const ptrs & units, const ptrs & race_units, const float & d) const -> void
	{
		if (_md == rs::Mode::LAND)
		{
			std::cout << (ENGLISH ? "Race for land units. "
						  : "Гонка для наземного транспорта. ");
		}
		else if (_md == rs::Mode::AIR)
		{
			std::cout << (ENGLISH ? "Race for air units. "
						  : "Гонка для воздушного транспорта. ");
		}
		else
		{
			std::cout << (ENGLISH ? "Race for land and air units. "
						  : "Гонка для наземного и воздушного транспорта. ");
		}

		std::cout << (ENGLISH ? "Distance: " : "Динстанция: ") << d << '\n' << '\n';

		if (race_units.empty())
		{
			std::cout << (ENGLISH ? "No units registered yet.\n"
						  : "Нет зарегистрированного транспорта.\n");
		}
		else
		{
			std::cout << (ENGLISH ? "Registered units:\n"
						  : "Зарегистрированный транспорт:\n");

			for (int i = 0; i < race_units.size(); ++i)
			{
				std::cout << i + 1 << ": " << race_units[i]->get_name() << '\n';
			}
		}

		std::cout << '\n';

		if (units.empty())
		{
			std::cout << (ENGLISH ? "All units added!\n" : "Весь транспорт добавлен!\n");
		}
		else
		{
			for (int i = 0; i < units.size(); ++i)
			{
				std::cout << i + 1 << ": " << units[i]->get_name() << '\n';
			}
		}

		std::cout << '\n' << (ENGLISH ? "Pick a unit ('A' to add all, 'X' to continue): "
							  : "Выберите транспорт ('A' добавить всех, 'X' продолжить): ");
	}

	auto Display::end_menu(const ptrs & race_units) const -> void
	{
		std::cout.setf(std::ios_base::fixed);
		std::cout.precision(2);

		if (ENGLISH)
		{
			std::cout << "The winner is:\n" << race_units[0]->get_name();
			std::cout << " with score " << race_units[0]->get_result() << "!\n\n";
			std::cout << "The loosers are:\n";
		}
		else
		{
			std::cout << "Победитель:\n" << race_units[0]->get_name();
			std::cout << " со счётои " << race_units[0]->get_result() << "!\n\n";
			std::cout << "Проигравшие:\n";
		}

		for (int i = 1; i < race_units.size(); ++i)
		{
			std::cout << i + 1 << ": " << race_units[i]->get_name() << " ";
			std::cout << race_units[i]->get_result() << '\n';
		}

		std::cout << (ENGLISH ? "\n'X' to exit, 'R' to restart: "
					  : "\n'X' выйти, 'R' перезапустить гонку: ");
	}

	auto Display::warning() const -> void
	{
		std::cout << (ENGLISH ? "At least two units must be added!\n"
					  : "Должно быть добавлено два транспорта!\n");
	}

	auto Display::farewell() const -> void
	{
		std::cout << (ENGLISH ? "Bye!\n" : "Пока!\n");
	}
}

