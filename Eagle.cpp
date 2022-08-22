#include "Eagle.h"

namespace rs
{
	Eagle::Eagle(const std::string & name, int speed, float cancellation) : Magic_carpet(name, speed, cancellation) { }

	auto Eagle::calculation(float distance) -> void
	{
		commom_calculation(distance);
	}
}