#pragma once
#include "Display.h"

namespace rs
{
	class Units_ABC
	{
	public:
		Units_ABC(const std::string & name = "none", int speed = 0, float result = 0.0f);
		virtual ~Units_ABC() = default;
		virtual auto calculation(float distance) -> void = 0;
		auto get_name() const -> const std::string;
		auto get_result() const -> float;
	protected:
		std::string _name;
		int _speed;
		float _result;
	};
}