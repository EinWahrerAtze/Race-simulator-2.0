#include "Boots.h"

namespace rs
{
	All_terrain_boots::All_terrain_boots(const std::string & name, int speed, int ttr)
		: Camel(name, speed, ttr) { }

	auto All_terrain_boots::calculation(float distance) -> void
	{
		int stops = common_calculation(distance);

		if (stops != 0)
		{
			m_result += (stops - 1) * 5 + 10;
		}
	}
}