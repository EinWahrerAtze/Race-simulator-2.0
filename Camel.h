#pragma once
#include "Terrestrial.h"

namespace rs
{
	class Camel : public Terrestrial
	{
	public:
		Camel(const std::string & name = "Camel", int speed = 10, int ttr = 30);
		auto calculation(float distance) -> void override;
	};
}