#include <setjmp.h>

#define EXC_EMPTY_VALUE 1

// exits current process and prints 'message' if 'condition' is true
static inline void fail(bool condition, const char *message) {
    if (condition) {
        printf("\n%s", message);
        exit(1);
    }
}

// print array of strings 'argv' whose size is 'argc'
static inline void printArgs(int argc, const char **argv) {
    printf("dhc: %d", argc);
    for (int i = 0; i < argc; i++) {
        printf("\narg[%d]: %s", i, argv[i]);
    }
    printf("\n");
}

// allocates and return an array of all the strings in the argv
// jmp: jumps to the jmp_buf if any of the strings in argv is empty (throw)
// indexOfEmptyArg: sets the index of the arg 
static inline const char ** allocGetArgs(int argc, char **argv, jmp_buf *jmp, int *indexOfEmptyArg) {    
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
