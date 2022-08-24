#include "Magic_carpet.h"

namespace rs
{
	Magic_carpet::Magic_carpet(const std::string & name, int speed, float cancellation)
		: Air(name, speed, cancellation) {	}

	auto Magic_carpet::calculation(float distance) -> void
	{
		if (distance >= 1000 && distance < 5000)
		{
			_cancellation = 0.97f;
		}
		if (distance >= 5000 && distance < 10000)
		{
			_cancellation = 0.90f;
		}
		if (distance >= 10000)
		{
			_cancellation = 0.95f;
		}

		main_calculation(distance);
	}
}