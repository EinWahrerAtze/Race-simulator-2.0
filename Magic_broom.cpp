#include "Magic_broom.h"

namespace rs
{
	Magic_broom::Magic_broom(const std::string & name, int speed, float cancellation)
		: Air(name, speed, cancellation)
	{
	}

	auto Magic_broom::calculation(float distance) -> void
	{
		_cancellation = std::floorf(distance / 1000);
		_cancellation = (100 - _cancellation) / 100;
		main_calculation(distance);
	}
}