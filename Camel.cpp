#include "Camel.h"

namespace rs
{
	Camel::Camel(const std::string & name, int speed, int ttr)
		: Units_ABC(name, speed), m_time_till_rest{ttr} { }

	auto Camel::common_calculation(float distance) -> int
	{
		float race = m_speed * m_time_till_rest;

		if (race > distance)
		{
			m_result = distance / m_speed;
			return 0;
		}
		else
		{
			int stops = static_cast<int>(distance / race);
			m_result = distance / m_speed;
			return stops;
		}
	}

	auto Camel::calculation(float distance) -> void
	{
		int stops = common_calculation(distance);

		if (stops != 0)
		{
			m_result += (stops - 1) * 8 + 5;
		}
	}
}