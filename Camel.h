#pragma once
#include "Units_ABC.h"

namespace rs
{
	class Camel : public Units_ABC
	{
	public:
		Camel(const std::string & name = "Camel", int speed = 10, int ttr = 30);
		auto calculation(float distance) -> void override;
	protected:
		auto common_calculation(float distance) -> int;
		int m_time_till_rest;
	};
}