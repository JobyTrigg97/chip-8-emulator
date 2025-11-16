#include <array>

class Chip8{
	// unint8_t is an unsighned 8-bit integer type (0-255)
	// unit16_t is an unsigned 16-bit integer type (0-65535)
public:
	Chip8();
	void loadROM(const char* filename);
	void emulatorCycle();

	bool drawFlag;

	std::array<uint8_t, 2048> display; // 64x32 pixels = 2048 bytes	
	std::array<uint8_t, 16> keys; 

private:
	void initialize();

	std::array<uint8_t, 4096> memory;
	std::array<uint8_t, 16> registers;
	std::array<uint16_t, 16> stack; //stores  valus in chip-8s memory rangeing from 0x000 to 0xFFF (0 to 4095) so unit8_t is not sufficient

	uint16_t operactionCode;
	uint8_t stackPointer;
	uint16_t indexRegister; // using uint16_t because it needs to store memory addresses in hexadecimal format
	uint16_t programCounter; // current memory address of instruction being executed
	uint8_t delay_timer;
	uint8_t sound_timer;
};
