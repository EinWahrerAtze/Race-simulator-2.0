#pragma once
#include "Magic_carpet.h"

namespace rs
{
	class Magic_broom : public Magic_carpet
	{
	public:
		Magic_broom(const std::string & name = "Magic broom", int speed = 20, float cancellation = 0.0f);
		auto calculation(float distance) -> void final;
	};
}