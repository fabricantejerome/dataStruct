#ifndef SML_H
#define SML_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Definitions of available instructions */
#define READ	 10	//Read a word from keyboard and store it to location in memory
#define WRITE	 11	//Write a word from memory location to screen
#define LOAD	 20	//Load contents of memory location to accumulator
#define STORE	 21	//Store accumulator contents to memory location
#define PUT		 23	//Store to operand to current instruction_counter
#define ADD		 30	//Add contents of memory location to accumulator
#define SUBTRACT	 31	//Subtract contents of memory location from accumulator
#define DIVIDE	 32	//Divide contents of memory location from accumulator
#define MULTIPLY	 33	//Multiply contets of memory locaton to accumulator
#define BRANCH	 40	//Jump to a specific address in memory
#define BRANCHNEG	 41	//BRANCH if accumulator is negative
#define BRANCHZERO 42	//BRANCH if accumulator is zero
#define HALT	 43	//Halt program execution

struct SML
{
	int* memory;
	int mem_size;
	int accumulator;
	int operator;
	int operand;
};
typedef struct SML sml;

/* Initialize an SML structure */
void construct(sml* mach, int memory_size)
{
	mach->memory = (int*)calloc(memory_size, sizeof(int));
	mach->mem_size = memory_size;
	mach->accumulator = 0;
	mach->operator    = 0;
	mach->operand     = 0;
}

/* Clear an SML structure */
void deconstruct(sml*mach)
{
	if(!(mach->memory))return;
	free(mach->memory);
	mach->memory 	= NULL;
	mach->mem_size    = 0;
	mach->accumulator = 0;
	mach->operator    = 0;
	mach->operand     = 0;
}

/* Copy "instruction" to "mach" memory from 0 to "size" */
void load_instruction(sml*mach, int*instruction, int size)
{
	assert(mach && instruction);
	assert( size <= (mach->mem_size) );
	int x;
	for(x=0 ; x < size ; ++x)
		mach->memory[x] = instruction[x];
}

/* Execute instruction in "mach" memory base on "inst_register" at address "inst_counter" */
int compute_statement(sml*mach, int *inst_counter)
{
	switch(mach->operator)
	{
		case READ:
			scanf("%d", ((mach->memory)+(mach->operand)));
			break;
		case WRITE:
			printf("%d", *((mach->memory)+(mach->operand)));
			break;
		case LOAD:
			mach->accumulator = *(mach->memory+mach->operand);
			break;
		case STORE:
			*(mach->memory+mach->operand) = mach->accumulator;
			break;
		case PUT:
			*(mach->memory+(*inst_counter)) = mach->operand;
			break;
		case ADD:
			mach->accumulator += *(mach->memory+mach->operand);
			break;
		case SUBTRACT:
			mach->accumulator -= *(mach->memory+mach->operand);
			break;
		case DIVIDE:
			assert(*(mach->memory+mach->operand) > 0);
			mach->accumulator /= *(mach->memory+mach->operand);
			break;
		case MULTIPLY:
			mach->accumulator *= *(mach->memory+mach->operand);
			break;
		case BRANCH:
			*inst_counter = mach->operand-1;
			break;
		case BRANCHNEG:
			if(mach->accumulator < 0)
				*inst_counter = mach->operand-1;
			break;
		case BRANCHZERO:
			if(mach->accumulator == 0)
				*inst_counter = mach->operand-1;
			break;
		default:
			return 0;
	}
	*inst_counter += 1;
	return 1;
}

/* Execute the sequence of instructions stored in "mach" memory */
void execute_program(sml* mach)
{
	assert(mach);
	int inst_counter=0;
	int inst_register=0;

	do
	{
		inst_register  = mach->memory[inst_counter];
		mach->operator = inst_register/100;
		mach->operand  = inst_register%100;
	}while(compute_statement(mach, &inst_counter));

}

/* Print the contents of "mach" memory */
void print_memory(sml* mach)
{
	int x;
	printf("\n\n\n");
	for(x=0 ; x < mach->mem_size ; ++x)
	{
		printf("0x%04d: %+05d\t", x, mach->memory[x]);
		if((x+1)%5 == 0)putchar('\n');
	}
}


void fromFile(int*store, const int size, FILE* srcfile)
{
	char*input = (char*)calloc(6, sizeof(char));
	int x;

	for(x=0 ; x < size && !feof(srcfile) ; ++x)
	{
		fscanf(srcfile, "%s", input);
		if(input[0] == '+' || input[0] =='-')
			store[x] = atoi(input);
		else
			--x;
	}
	free(input);
}

void fromConsole(int*store, const int size)
{
	int x;
	for(x=0 ; x < size ; ++x)
	{
		printf("%03d? ", x);
		scanf("%d", &store[x]);
		if( store[x] == 0 )
			break;
	}
}

#endif
