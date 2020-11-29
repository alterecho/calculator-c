#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static int add(int n1, int n2);
static int subtract(int, int);
static int multiply(int, int);
static int divide(int, int);

#define OP_ADD "add"
#define OP_SUBTRACT "subtract"
#define OP_MULTIPLY "multiply"
#define OP_DIVIDE "divide"

typedef enum {
    op_unknown = -1,
    op_add = 0,
    op_subtract,
    op_multiply,
    op_divide,
} OpType;

/// return OpType from string (arg innto program)
static inline OpType opTypeFromString(const char *arg) {
    if(strcmp(arg, OP_ADD) == 0) {
        return op_add;
    } else if(strcmp(arg, OP_SUBTRACT) == 0) {
        return op_subtract;
    } else if(strcmp(arg, OP_MULTIPLY) == 0) {
        return op_multiply;
    } else if(strcmp(arg, OP_DIVIDE) == 0) {
        return op_divide;
    }
    return op_unknown;
}

static inline void fail(bool condition, const char *message) {
    if (condition) {
        printf("\n%s", message);
        exit(1);
    }
}

int main(int argc, char **argv) {
    
    for(int i = 0; i < argc; i++) {
        printf("arg: %s", argv[i]);
    }
    fail(argc < 2, "NO ARGS SUPPLIED");
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
            fail(1, "unknown operation %s");
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
