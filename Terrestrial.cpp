#include "Terrestrial.h"

namespace rs
{
	Terrestrial::Terrestrial(const std::string & name, int speed, int ttr)
		: Units_ABC(name, speed), _time_till_rest{ ttr } { }

	auto Terrestrial::main_calculation(float distance) -> int
	{
		float race = _speed * _time_till_rest;

		if (race > distance)
		{
			_result = distance / _speed;
			return 0;
		}
		else
		{
			int stops = static_cast<int>(distance / race);
			_result = distance / _speed;
			return stops;
		}
	}
}