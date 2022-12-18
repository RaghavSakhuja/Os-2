
#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE* demo;

	demo = fopen("OTHER.txt", "w");

	fclose(demo);
	demo = fopen("FIFO.txt", "w");

	fclose(demo);
	demo = fopen("RR.txt", "w");

	fclose(demo);

	return 0;
}
