#include "Chip8.h"
#include<iostream>
#include<fstream>
#include<vector>

Chip8::Chip8() {
	initialize();
}
void Chip8::initialize() {
	programCounter = 0x200; //starting memory address; chip-8 started the game at 0x200. 0x000 was reserved for the interpreter
	operationCode = 0;
	indexRegister = 0;
	stackPointer = 0;

	memory.fill(0);
	registers.fill(0);
	stack.fill(0);
	display.fill(0);
	keys.fill(0);

	delay_timer = 0;
	sound_timer = 0;

	uint8_t fontset[80] = {
		0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
		0x20, 0x60, 0x20, 0x20, 0x70, // 1        
		0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
		0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3 
		0x90, 0x90, 0xF0, 0x10, 0x10, // 4
		0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
		0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
		0xF0, 0x10, 0x20, 0x40, 0x40, // 7
		0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
		0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
		0xF0, 0x90, 0xF0, 0x90, 0x90, // A
		0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
		0xF0, 0x80, 0x80, 0x80, 0xF0, // C
		0xE0, 0x90, 0x90, 0x90, 0xE0, // D
		0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
		0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};

	for (int i = 0; i < 80; ++i) {
		memory[i] = fontset[i];
	}
}
void Chip8::loadROM(const char* filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::ate); // raw binary data and place the read pointer at the end of the file
	if (!file) {
		std::cerr << "Failed to open ROM\n";
		return;
	}
	std::streamsize size = file.tellg(); // get file size
	file.seekg(0, std::ios::beg); // now we have the file size move the read pointer to the start of the file 

	std::vector<char> buffer(size);
	if (file.read(buffer.data(), size)) {
		for (size_t i = 0; i < buffer.size(); ++i) {
			memory[0x200 + i] = buffer[i]; //chip-8 started the game at 0x200 0x000 was reserved for the interpreter
		}
	}
	file.close();
}
