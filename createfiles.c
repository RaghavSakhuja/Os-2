
#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE* demo;

	demo = fopen("fork1.txt", "w");

	fclose(demo);
	demo = fopen("fork2.txt", "w");

	fclose(demo);
	demo = fopen("fork3.txt", "w");

	fclose(demo);

	return 0;
}
