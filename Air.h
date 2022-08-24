#pragma once
#include "Units_ABC.h"

namespace rs
{
	class Air : public Units_ABC
	{
	public:
		Air(const std::string & name = "none", int speed = 0, float cancellation = 0);
	protected:
		auto main_calculation(float distance) -> void;
		float _cancellation;
	};
}
