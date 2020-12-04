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
	int result;
	__asm__ __volatile__ (
		"mul %%ebx"
		: "=a" (result)
		: "a" (n2), "b"(n1)
	);
	return result;
}

int divide(int n1, int n2) {
	int result, quotient, remainder, eax, ebx, ecx, edx;
	__asm__ __volatile__ ( 
		"movl $0x0, %%edx\n\t"
		"div %%ebx"
		: "=a" (quotient), "=d" (remainder), "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
		: "a" (n1), "b" (n2)
	);
	result = quotient;
	return quotient;
}
