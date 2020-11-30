#include <setjmp.h>

#define EXC_EMPTY_VALUE 1

static inline void fail(bool condition, const char *message) {
    if (condition) {
        printf("\n%s", message);
        exit(1);
    }
}

static inline const char **allocGetArgs(int argc, char **argv, jmp_buf *jmp, int *indexOfEmptyArg) {    
    char **args = (char **)malloc(sizeof(char *) * argc);
    for (int i = 0; i < argc; i++) {
        size_t len = strlen(argv[i]);
        if (jmp != NULL) {
            if (len < 1) {
                if (indexOfEmptyArg != NULL) {
                    *indexOfEmptyArg = i;
                }
                longjmp(*jmp, EXC_EMPTY_VALUE);
            }
        }

        size_t size = len + 1;
        char *arg = (char *)malloc(size);
        arg = strcpy(arg, argv[i]);
        args[i] = arg;
    }
    return (const char **)args;
}
