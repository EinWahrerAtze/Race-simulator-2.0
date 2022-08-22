//
//  Keyboard.h
//  Race_simulator_v2
//
//  Created by Den Fedorov on 19.08.2022.
//

#pragma once
#include <iostream>
#include <array>

namespace rs
{
	template<typename T, std::size_t S>
	class Check
	{
	public:
		template<typename... Ts>
		Check(Ts... args) : elements{args...}
		{
			// if number of passed arguments greater than array size S -> compile time error
			static_assert(sizeof... (Ts) == S, "invalid number of arguments");
			// if type of passed arguments if different from T -> compile time error
			static_assert((std::is_same_v<T, Ts> & ...), "invalid type of arguments");
		}
		auto find(const T & element) -> T
		{
			auto found = std::find(std::begin(elements), std::end(elements), element);
			return (found != std::end(elements) ? element : 0);
		}
	private:
		std::array<T, S> elements;
	};
}
