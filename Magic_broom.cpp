#include "Magic_broom.h"

namespace rs
{
	Magic_broom::Magic_broom(const std::string & name, int speed, float cancellation) : Magic_carpet(name, speed, cancellation)	{ }

	auto Magic_broom::calculation(float distance) -> void
	{
		m_cancellation = std::floorf(distance / 1000);
		m_cancellation = (100 - m_cancellation) / 100;
		commom_calculation(distance);
	}
}