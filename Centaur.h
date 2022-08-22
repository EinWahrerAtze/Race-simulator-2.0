#pragma once
#include "Camel.h"

namespace rs
{
	class Centaur : public Camel
	{
	public:
		Centaur(const std::string & name = "Centaur", int speed = 15, int ttr = 8);
		auto calculation(float distance) -> void override;
	};
}