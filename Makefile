main: main.c common.h OpType.h math.*
	gcc main.c math.c OpType.c -g -o main
