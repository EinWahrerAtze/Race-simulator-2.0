#include "Air.h"

namespace rs
{
	Air::Air(const std::string & name, int speed, float cancellation)
		: Units_ABC(name, speed), _cancellation{ cancellation } { }

	auto Air::main_calculation(float distance) -> void
	{
		distance *= _cancellation;
		_result = distance / _speed;
	}
}