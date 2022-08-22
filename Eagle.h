#pragma once
#include "Magic_carpet.h"

namespace rs
{
	class Eagle : public Magic_carpet
	{
	public:
		Eagle(const std::string & name = "Eagle", int speed = 8, float cancellation = 0.94f);
		auto calculation(float distance) -> void override;
	};
}