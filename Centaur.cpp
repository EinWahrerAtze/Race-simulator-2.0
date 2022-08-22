#include "Centaur.h"

namespace rs
{
	Centaur::Centaur(const std::string & name, int speed, int ttr)
		: Camel(name, speed, ttr) { }

	auto Centaur::calculation(float distance) -> void
	{
		int stops = common_calculation(distance);

		if (stops != 0)
		{
			m_result += stops * 2;
		}
	}
}