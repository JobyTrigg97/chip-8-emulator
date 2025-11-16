#include "Chip8.h"
#include<iostream>
#include<fstream>
#include<vector>

Chip8::Chip8() {
	initialize();
}
void Chip8::initialize() {
	programCounter = 0x200; //staring memory address
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
}