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

double subtract(double n1, double n2) {
	int result;
	// __asm__ __volatile__ (
	
	// "SUB %1, %0;\n\t"
	// : "=c" (result)
	// : "a" (n2), "b" (n1)
	// );
	return result;
}

double multiply(double n1, double n2) {
	return 0;
}

double divide(double n1, double n2) {
	return 0;
}
