#include <array>

Class Chip8{
	// unint8_t is an unsighned 8-bit integer type (0-255) therefor is used to represent a single byte
public:
	std::array<uint8_t, 2048> display; // 64x32 pixels = 2048 bytes	
	std::array<uint8_t, 16> keys; 
private:
	std::array<uint8_t, 4096> memory;
	std::array<uint8_t, 16> registers;
	std::array<uint16_t, 16> stack;
};
