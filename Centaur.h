#pragma once
#include "Terrestrial.h"

namespace rs
{
	class Centaur : public Terrestrial
	{
	public:
		Centaur(const std::string & name = "Centaur", int speed = 15, int ttr = 8);
		auto calculation(float distance) -> void override;
	};
}