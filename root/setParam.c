#include <stdio.h>
#include <lib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int group;
    int value;
    int ret;
    message m1;

    if (argc != 3) {
    	printf("Wrong args number: %d\n", argc);
    	exit(1);
    }

    group = atoi(argv[1]);
    value = atoi(argv[2]);
    m1.m1_i1 = group;
    m1.m1_i2 = value;

    ret = _syscall( MM_PROC_NR, SETGPARAM, &m1 );
    printf("%d\n", ret);

    return 0;
}
