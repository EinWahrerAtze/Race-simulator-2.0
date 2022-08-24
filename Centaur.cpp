#include "Centaur.h"

namespace rs
{
	Centaur::Centaur(const std::string & name, int speed, int ttr)
		: Terrestrial(name, speed, ttr)	{ }

	auto Centaur::calculation(float distance) -> void
	{
		int stops = main_calculation(distance);

		if (stops != 0)
		{
			_result += stops * 2;
		}
	}
}