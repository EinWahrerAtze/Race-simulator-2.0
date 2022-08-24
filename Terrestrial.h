#pragma once
#include "Units_ABC.h"

namespace rs
{
	class Terrestrial : public Units_ABC
	{
	public:
		Terrestrial(const std::string & name = "none", int speed = 0, int ttr = 0);
	protected:
		auto main_calculation(float distance) -> int;
		int _time_till_rest;
	};
}
