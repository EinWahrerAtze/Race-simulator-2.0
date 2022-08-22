//
//  Display.h
//  Race_simulator_v2
//
//  Created by Den Fedorov on 19.08.2022.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Units_ABC.h"

#define ptrs std::vector<std::unique_ptr<rs::Units_ABC>>
#define ENGLISH _lng == Lang::ENG

namespace rs
{
	// forward declaration
	class Units_ABC;

	enum class Lang
	{
		ENG,
		RUS
	};

	enum class Mode
	{
		LAND,
		AIR,
		ALL
	};

	class Display
	{
	public:
		Display(Lang lng = Lang::ENG, Mode md = Mode::ALL);
		~Display();
		auto greetings() const-> void;
		auto main_menu() const -> void;
		auto set_locale() -> void;
		auto set_mode(Mode md) -> void;
		auto get_lang() const -> const Lang &;
		auto distance() const -> void;
		auto wrong_input() const -> void;
		auto units_menu(const ptrs & units, const ptrs & race_units, const float & d) const -> void;
		auto end_menu(const ptrs & race_units) const -> void;
		auto warning() const -> void;
		auto farewell() const -> void;
	private:
		Lang _lng;
		Mode _md;
		std::vector<std::string> _units;
	};
}

