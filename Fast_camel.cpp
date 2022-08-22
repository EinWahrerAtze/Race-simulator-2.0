#include "Fast_camel.h"

namespace rs
{
	Fast_camel::Fast_camel(const std::string & name, int speed, int ttr)
		: Camel(name, speed, ttr) { }

	auto Fast_camel::calculation(float distance) -> void
	{
		int stops = common_calculation(distance);
		m_result += 5;

		if (stops > 1)
		{
			m_result += (stops - 2) * 8;
		}
	}
}