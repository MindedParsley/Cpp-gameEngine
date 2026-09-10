#include <DX3D/All.h>

int main() {
	try {
		dx3d::Game game({ dx3d::Logger::LogLevel::info });
		game.run();
	}
	catch (const std::runtime_error& e) {
		return EXIT_FAILURE;
	}
	catch (const std::exception& e) {
		return EXIT_FAILURE;
	}
	catch (...) {
		return EXIT_FAILURE;
	}
	return 0;

}