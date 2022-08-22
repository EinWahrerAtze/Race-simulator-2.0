#pragma once
#include "Units_ABC.h"

namespace rs
{
	class Magic_carpet : public Units_ABC
	{
	public:
		Magic_carpet(const std::string & name = "Magic carpet", int speed = 10, float cancellation = 0.0f);
		auto calculation(float distance) -> void override;
	protected:
		auto commom_calculation(float distance) -> void;
		float m_cancellation;
	};
}