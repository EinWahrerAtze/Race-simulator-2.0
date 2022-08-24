#pragma once
#include "Terrestrial.h"

namespace rs
{
	class All_terrain_boots : public Terrestrial
	{
	public:
		All_terrain_boots(const std::string & name = "All terrain boots", int speed = 6, int ttr = 60);
		auto calculation(float distance) -> void final;
	};
}