#include "sml.h"



int main(int argc, char**argv)
{
	sml machine;
	int MEM_SIZE=100;
	
	int* instructions = (int*)calloc(MEM_SIZE,sizeof(int));

	fromConsole(instructions, MEM_SIZE);

	construct(&machine, MEM_SIZE);
	load_instruction(&machine, instructions, MEM_SIZE);
	execute_program(&machine);
	print_memory(&machine);
	deconstruct(&machine);

	return 0;
}
