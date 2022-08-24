#include "Camel.h"

namespace rs
{
	Camel::Camel(const std::string & name, int speed, int ttr)
		: Terrestrial(name, speed, ttr) { }

	auto Camel::calculation(float distance) -> void
	{
		int stops = main_calculation(distance);

		if (stops != 0)
		{
			_result += (stops - 1) * 8 + 5;
		}
	}
}