#include "memtest.h"

char* memory;

void deleteHeap()
{
	delete memory;
}

void firstpass(int a)
{
	int pass[2500];
	for (int i = 0; i < 2500; i++){
		pass[i] = a;
	}

	for (int i = 0; i < 2500; i++){
		memory[i] = pass[i];
	}
}

void secondpass(int a)
{
	int pass[2500];
	for (int i = 0; i < 2500; i++){
		pass[i] = a;
	}

	for (int i = 2500; i < 5000; i++){
		memory[i] = pass[i-2500];
	}
}

void loadHeap1()
{
	deleteHeap();
	memory = new char [5000];
	firstpass(0xF1);
	secondpass(0xF2);
}



void loadHeap2()
{
	deleteHeap();

	memory = new char[5000];
	firstpass(0xF2);
	secondpass(0xF1);
}


