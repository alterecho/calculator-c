#ifndef OP_TYPE_H
#define OP_TYPE_H

#include <string.h>

/*
suffix:
    _S -- short variant
*/
#define OP_ADD "add"

#define OP_SUBTRACT "subtract"
#define OP_SUBTRACT_S "sub"

#define OP_MULTIPLY "multiply"
#define OP_MULTIPLY_S "mul"

#define OP_DIVIDE "divide"
#define OP_DIVIDE_S "div" 

typedef enum {
    op_unknown = -1,
    op_add = 0,
    op_subtract,
    op_multiply,
    op_divide,
} OpType;

OpType opTypeFromString(const char *arg);

#endif