#pragma once
#include "Terrestrial.h"

namespace rs
{
	class Fast_camel : public Terrestrial
	{
	public:
		Fast_camel(const std::string & name = "Fast camel", int speed = 40, int ttr = 10);
		auto calculation(float distance) -> void override;
	};
}
