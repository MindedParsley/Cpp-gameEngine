#pragma once
#include <DX3D/Core/Base.h>

namespace dx3d
{
	class Logger final : public Base
	{
	public:
		enum class LogLevel
		{
			error = 0,
			warning = 1,
			info = 2
		};

		explicit Logger(LogLevel logLevel = LogLevel::error);
		void log(LogLevel Level, const char* message) const;

	private:
		LogLevel m_logLevel = LogLevel::error;
	};
}
