#include <DX3D/Core/Logger.h>
#include <iostream>

dx3d::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	std::clog << "JK | C++ game engine" << '\n';
	std::clog << "------------------------------------------------------------------" << '\n';
}

void dx3d::Logger::log(LogLevel Level, const char* message) const
{
	auto loglevelToString = [](LogLevel level){
		switch (level)
		{
		case LogLevel::error: return "ERROR";
		case LogLevel::warning: return "WARNING";
		case LogLevel::info: return "INFO";
		default: return "UNKNOWN";
		}
	};

	if (Level > m_logLevel) return;
	std::clog << "[DX3D " << loglevelToString(Level) << "]: " << message << '\n';
}

