#import "math.h"
#import <stdio.h>

int add(int n1, int n2) {
	int result;
	__asm__ __volatile__ (
	"movl %1, %%eax;\n\t"
	"addl %2, %%eax;\n\t"
	"movl %%eax, %0;\n\t"
	: "=r"(result)
	: "r" (n1), "r"(n2)
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
 
int multiply(int n1, int n2) {
	return 0;
}

int divide(int n1, int n2) {
	return 0;
}
