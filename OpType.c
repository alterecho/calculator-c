#import "OpType.h"

/// return OpType from string (arg innto program)
inline OpType opTypeFromString(const char *arg) {
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

