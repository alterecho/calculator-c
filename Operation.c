#import "Operation.h"
#include <stdlib.h>
#include "common.h"

Operation operationFromArgs(int argc, char **argv) {
    Operation operation
    operation.type = opTypeFromString
    return operation
}

static inline Operation operationFromArgs(int argc, char **argv) {    
    OpType opType = opTypeFromString(argv[1]);

    // args passed in
    char *arg1 = argv[2];
    char *arg2 = argv[3];

    // is FPU op
    bool isFP = isFloatingPointOp(arg1, arg2);

    // save input as double
    double n1 = atof(arg1);
    double n2 = atof(arg2);

    Operation op = {
        opType,
        isFP,
        { n1, n2 }
    };

    return op;
}