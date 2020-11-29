#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "OpType.h"
#include "common.h"

static int add(int n1, int n2);
static int subtract(int, int);
static int multiply(int, int);
static int divide(int, int);

int main(int argc, char **argv) {
    for(int i = 0; i < argc; i++) {
        printf("arg: %s", argv[i]);
    }
    fail(argc < 2, "NO ARGS SUPPLIED");

    //operation input
    const char *ip_op = argv[1];
    OpType opType = opTypeFromString(ip_op);
    
    switch (opType) {
        case op_add:
            fail(argc < 4, "add needs 2 arguments");
            break;
        case op_subtract:
            fail(argc < 4, "subtract needs 2 arguments");
            break;
        case op_multiply:
            fail(argc < 4, "multiply needs 2 arguments");
            break;
        case op_divide:
            fail(argc < 4, "divide needs 2 arguments");
            break;
        default:
        {
            const char *prefix = "unknown operation ";
            size_t len = strlen(prefix) + 1 /* space */ + strlen(ip_op);
            char *msg = (char *)malloc(sizeof(char) * len);
            snprintf(msg, sizeof(msg), " %s", ip_op);
            fail(1, msg);
        }
        break;
    }
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
