#pragma once
#include "Camel.h"

namespace rs
{
	class All_terrain_boots : public Camel
	{
	public:
		All_terrain_boots(const std::string & name = "All terrain boots", int speed = 6, int ttr = 60);
		auto calculation(float distance) -> void final;
	};
}