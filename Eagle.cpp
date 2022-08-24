#include "Eagle.h"

namespace rs
{
	Eagle::Eagle(const std::string & name, int speed, float cancellation) 
		: Air(name, speed, cancellation) { }

	auto Eagle::calculation(float distance) -> void
	{
		main_calculation(distance);
	}
}