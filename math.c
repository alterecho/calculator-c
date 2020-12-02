#import "math.h"

double add(int n1, int n2) {
	int result;
	__asm__ __volatile__ (
	"movl %1, %%eax;\n\t"
	"addl %2, %%eax;\n\t"
	"movl %%eax, %0;\n\t"
	: "=d"(result)
	: "b" (n1), "c"(n2)
	: "%eax"
	);
	return result;
}

int subtract(int n1, int n2) {
	int result;
	__asm__ __volatile__ (
	"subl %%ebx, %%eax;\n\t"
	: "=a" (result)
	: "b" (n2), "a" (n1)
	);
	return result;
}

double multiply(double n1, double n2) {
	return 0;
}

double divide(double n1, double n2) {
	return 0;
}
