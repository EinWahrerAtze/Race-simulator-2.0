#include "Units_ABC.h"

namespace rs
{
	Units_ABC::Units_ABC(const std::string & name, int speed, float result)
		: m_name{name}, m_speed{speed}, m_result{result} { }

	auto Units_ABC::get_name() const -> const std::string &
	{
		return m_name;
	}

	auto Units_ABC::get_result() const -> float
	{
		return m_result;
	}
}