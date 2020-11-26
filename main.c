#include <stdio.h>

static int add(int n1, int n2);
static int subtract(int, int);
static int multiply(int, int);
static int divide(int, int);

int main(int argc, int **argv) {
	printf("\nin main: argc: %d, argv: %p", argc, argv);	
	printf("\nadd: %d", add(2, 3));\
	printf("\nsub: %d", subtract(2, 3));
	printf("\nmultiply: %d", multiply(2, 3));
	printf("\ndivide: %d", divide(2, 3));
	return 0;
}

static int add(int n1, int n2) {
	int result;
	__asm__ __volatile__ (
	"MOV %1, %%eax;\n\t"
	"ADD %2, %%eax;\n\t"
	"MOV %%eax, %0;\n\t"
	: "=d"(result)
	: "b" (n1), "c"(n2)
	: "%eax"
	);
	return result;
}

static int subtract(int n1, int n2) {
	int result;
	__asm__ __volatile__ (
	
	"SUB %1, %0;\n\t"
	: "=c" (result)
	: "a" (n2), "b" (n1)
	);
	return result;
}

static int multiply(int n1, int n2) {
	return 0;
}

static int divide(int n1, int n2) {
	return 0;
}