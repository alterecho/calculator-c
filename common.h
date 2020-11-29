static inline void fail(bool condition, const char *message) {
    if (condition) {
        printf("\n%s", message);
        exit(1);
    }
}