#include <string.h>

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

OpType opTypeFromString(const char *arg);
