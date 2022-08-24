#include "Fast_camel.h"

namespace rs
{
	Fast_camel::Fast_camel(const std::string & name, int speed, int ttr)
		: Terrestrial(name, speed, ttr) { }

	auto Fast_camel::calculation(float distance) -> void
	{
		int stops = main_calculation(distance);
		_result += 5;

		if (stops > 1)
		{
			_result += (stops - 2) * 8;
		}
	}
}