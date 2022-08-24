#include "Units_ABC.h"

namespace rs
{
	Units_ABC::Units_ABC(const std::string & name, int speed, float result)
		: _name{ name }, _speed{ speed }, _result{ result }
	{
	}

	auto Units_ABC::get_name() const -> const std::string
	{
		return _name;
	}

	auto Units_ABC::get_result() const -> float
	{
		return _result;
	}
}