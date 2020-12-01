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