main: main.c common.h OpType.h math.* Operation.*
	gcc main.c math.c OpType.c -g -o main
