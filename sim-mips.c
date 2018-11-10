// Author: Shikang Xu; ECE 353 TA
#define _CRT_SECURE_NO_WARNINGS
// List the full names of ALL group members at the top of your code.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
//feel free to add here any additional library names you may need 
#define SINGLE 1
#define BATCH 0
#define REG_NUM 32

char *progScanner(char *ptr);
char *regNumberConverter(char *ptr);
struct inst parser(char *ptr);

//type definition of struct type instruction
typedef struct inst {
	int opcode;
	int reg1;
	int reg2;
	int reg3;
	int imm;
};

main(int argc, char *argv[]) {
	int sim_mode = 0;//mode flag, 1 for single-cycle, 0 for batch
	int c, m, n;
	int i;//for loop counter
	long mips_reg[REG_NUM];
	long pgm_c = 0;//program counter
	long sim_cycle = 0;//simulation cycle counter
	//define your own counter for the usage of each pipeline stage here

	int test_counter = 0;
	FILE *input = NULL;
	FILE *output = NULL;
	printf("The arguments are:");

	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");
	if (argc == 7) {
		if (strcmp("-s", argv[1]) == 0) {
			sim_mode = SINGLE;
		}
		else if (strcmp("-b", argv[1]) == 0) {
			sim_mode = BATCH;
		}
		else {
			printf("Wrong sim mode chosen\n");
			exit(0);
		}

		m = atoi(argv[2]);
		n = atoi(argv[3]);
		c = atoi(argv[4]);
		input = fopen(argv[5], "r");
		output = fopen(argv[6], "w");

		printf("Argv 5 is %s\n", argv[5]);
		char *linePtr = NULL;
		char *correctedLinePtr = NULL;
		
		linePtr = malloc(200 * sizeof(char));
		correctedLinePtr = malloc(200 * sizeof(char));

		while (fgets(linePtr, 100, input)) {
			//printf("String input is %s \n", linePtr);
			//printf("Line pointer is point to char: %c\n", *linePtr);
			//Send the input to prog scanner for corrections
			correctedLinePtr = progScanner(linePtr);
			correctedLinePtr = regNumberConverter(correctedLinePtr);
			//Print the returned pointer
			printf("\nCorrected line pointer is point to char: %s\n", correctedLinePtr);
			//test parset function
			struct inst temp;
			temp = parser(correctedLinePtr);
			printf("\nReturned struct: %d", temp.reg1);
		}
		fclose(input);
	}

	else {
		printf("Usage: ./sim-mips -s m n c input_name output_name (single-sysle mode)\n or \n ./sim-mips -b m n c input_name  output_name(batch mode)\n");
		printf("m,n,c stand for number of cycles needed by multiplication, other operation, and memory access, respectively\n");
		exit(0);
	}
	if (input == NULL) {
		printf("Unable to open input or output file\n");
		exit(0);
	}
	if (output == NULL) {
		printf("Cannot create output file\n");
		exit(0);
	}
	//initialize registers and program counter
	if (sim_mode == 1) {
		for (i = 0; i < REG_NUM; i++) {
			mips_reg[i] = 0;
		}
	}

	//start your code from here
}

char *progScanner(char *ptr)
{
	char *newLine = NULL;
	//printf("\nLine pointer is point to char: %c", *ptr);
	printf("\nString input inside prog scanner %s", ptr);
	
	//Do some stuff here to correct the input and then send back a pointer to new string
	newLine = ptr;
	return newLine;
}

char *regNumberConverter(char *ptr)
{
	char *newLine = NULL;
	printf("\nString input inside regNumberConverter %s", ptr);

	//Do some stuff here to correct the input and then send back a pointer to new string
	newLine = ptr;
	return newLine;
}

struct inst parser(char *ptr)
{
	//test code to make sure ptr is received
	printf("\nString input inside parser: %s", ptr);

	//translate the ptr instructon line to a structure
	//return the struct
	//just some test code
	struct inst temp;
	temp.reg1 = 9;
	return temp;
}

