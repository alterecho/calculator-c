#import "OpType.h"

/// return OpType from string (arg innto program)
inline OpType opTypeFromString(const char *arg) {
    if(strcmp(arg, OP_ADD) == 0) {
        return op_add;
    } else if(strcmp(arg, OP_SUBTRACT) == 0 || strcmp(arg, OP_SUBTRACT_S) == 0) {
        return op_subtract;
    } else if(strcmp(arg, OP_MULTIPLY) == 0 || strcmp(arg, OP_MULTIPLY_S) == 0) {
        return op_multiply;
    } else if(strcmp(arg, OP_DIVIDE) == 0 || strcmp(arg, OP_DIVIDE_S) == 0) {
        return op_divide;
    }
    return op_unknown;
}

