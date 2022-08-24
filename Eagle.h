#pragma once
#include "Air.h"

namespace rs
{
	class Eagle : public Air
	{
	public:
		Eagle(const std::string & name = "Eagle", int speed = 8, float cancellation = 0.94f);
		auto calculation(float distance) -> void override;
	};
}