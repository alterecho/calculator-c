#ifndef OPERATION_H
#define OPERATION_H

#include <stdbool.h>
#include "OpType.h"

// meta data for the program input
// params are stored as double, eben if int
typedef struct {
    OpType type;
    // is floating point operation
    bool isFP;
    double params[2];
} Operation;

// returns an Operation init with the program args
static inline Operation operationFromArgs(int argc, char **argv);

#endif