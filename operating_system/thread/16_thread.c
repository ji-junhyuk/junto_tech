#include <stdio.h>
#include <omp.h>

#define SIZE 100000000

int a[SIZE], b[SIZE], c[SIZE];

int main(int argc, char *argv[])
{
	for (int idx = 0; idx < SIZE; ++idx)
		a[idx] = b[idx] = idx;

	#pragma omp parallel for
	for (int idx = 0; idx < SIZE; ++idx)
		c[idx] = a[idx] + b[idx];
	// time a.out
	return 0;
}
