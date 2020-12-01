#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "OpType.h"
#include "common.h"
#import "math.h"

static inline void opAdd(int n1, int n2);
static inline void opSubtract();
static inline void opMultiply();
static inline void opDivide();


int main(int argc, char **argv) {
    printArgs(argc, (const char **) argv);
    fail(argc < 2, "NO ARGS SUPPLIED");

    //operation input
    const char *ip_op = argv[1];
    OpType opType = opTypeFromString(ip_op);

    jmp_buf exception;
    int indexOfEmptyArg = -1;

    const char **args = NULL;
    if (setjmp(exception)) {
        printf("\nargument %d is empty", indexOfEmptyArg);
        exit(1);
    } else {
        const char **args = allocGetArgs(argc, argv, &exception, &indexOfEmptyArg);
    }
    
    switch (opType) {
        case op_add:
            fail(argc < 4, "add needs 2 arguments");
            opAdd(atoi(argv[2]), atof(argv[3]));
            break;
        case op_subtract:
            fail(argc < 4, "subtract needs 2 arguments");
            opSubtract(atof(argv[2]), atof(argv[3]));
            break;
        case op_multiply:
            fail(argc < 4, "multiply needs 2 arguments");
            opMultiply(atof(argv[2]), atof(argv[3]));
            break;
        case op_divide:
            fail(argc < 4, "divide needs 2 arguments");
            opDivide(atof(argv[2]), atof(argv[3]));
            break;
        default:
        {
            const char *prefix = "unknown operation\0";
            size_t len = strlen(prefix) + 1 /* space */ + strlen(ip_op);
            size_t size = sizeof(char) * len;
            char *msg = (char *)malloc(size);
            snprintf(msg, 100, "%s %s", prefix, ip_op);
            fail(1, msg);
        }
        break;
    }
    return 0;
}

static inline void opAdd(int n1, int n2) {
    int res = add(n1, n2);
    printf("\n%d + %d = %d", n1, n2, res);
}

static inline void opSubtract(double n1, double n2) {
    double res = subtract(n1, n2);
    printf("\n%f - %f = %f", n1, n2, res);
}

static inline void opMultiply(double n1, double n2) {
    double res = multiply(n1, n2);
    printf("\n%f X %f = %f", n1, n2, res);
}

static inline void opDivide(double n1, double n2) {
    double res = divide(n1, n2);
    printf("\n%f / %f = %f", n1, n2, res);
}

