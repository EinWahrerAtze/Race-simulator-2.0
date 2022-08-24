#pragma once
#include "Air.h"

namespace rs
{
	class Magic_carpet : public Air
	{
	public:
		Magic_carpet(const std::string & name = "Magic carpet", int speed = 10, float cancellation = 0.0f);
		auto calculation(float distance) -> void override;
	};
}