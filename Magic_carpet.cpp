#include "Magic_carpet.h"

namespace rs
{
	Magic_carpet::Magic_carpet(const std::string & name, int speed, float cancellation) : Units_ABC(name, speed), m_cancellation{cancellation} { }

	auto Magic_carpet::commom_calculation(float distance) -> void
	{
		distance *= m_cancellation;
		m_result = distance / m_speed;
	}

	auto Magic_carpet::calculation(float distance) -> void
	{
		if (distance >= 1000 && distance < 5000)
		{
			m_cancellation = 0.97f;
		}
		if (distance >= 5000 && distance < 10000)
		{
			m_cancellation = 0.90f;
		}
		if (distance >= 10000)
		{
			m_cancellation = 0.95f;
		}

		commom_calculation(distance);
	}
}