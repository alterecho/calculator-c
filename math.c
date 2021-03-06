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

double addf(double n1, double n2) {
	double res = 2.0;
	__asm__ __volatile__(
		"fldl %1\n\t"
		"faddl %2\n\t"
		/* "fldl %2\n\t" "fadd %%st(1)\n\t" */ // another form (comment out previious forms)
		: "=t" (res) /* t -- top of stack */
		: "m" (n1), "m" (n2) /* m -- memory */
	);
	
	return res;
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

double subtractf(double n1, double n2) {
	double res = 0;
	__asm__ __volatile__ (
		"fldl %1\n\t"
		"fsubl %2\n\t"
		: "=t" (res)
		: "g" (n1), "g" (n2)
	);
	return res;
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

double multiplyf(double n1, double n2) {
	double res = 0;
	__asm__ __volatile__ (
		"fldl %1\n\t"
		"fmull %2\n\t"
		: "=t" (res)
		: "g" (n1), "g" (n2)
	);
	return res;
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

double dividef(double n1, double n2) {
	double res = 0;
	__asm__ __volatile__ (
		"fldl %1\n\t"
		"fdivl %2\n\t"
		: "=t" (res)
		: "g" (n1), "g" (n2)
	);
	printf("\ndividef red: %f", res);
	return res;
}
