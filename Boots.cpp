#include "Boots.h"

namespace rs
{
	All_terrain_boots::All_terrain_boots(const std::string & name, int speed, int ttr) 
		: Terrestrial(name, speed, ttr)	{ }

	auto All_terrain_boots::calculation(float distance) -> void
	{
		int stops = main_calculation(distance);

		if (stops != 0)
		{
			_result += (stops - 1) * 5 + 10;
		}
	}
}