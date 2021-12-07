#include <stdio.h>
#include <lib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int group;
    int ret;
    message m1;

    if (argc != 2) {
    	printf("Wrong args number: %d\n", argc);
    	exit(1);
    }

    group = atoi(argv[1]);
    m1.m1_i1 = group;

    ret = _syscall( MM_PROC_NR, GETGPARAM, &m1 );
    printf("%d\n", ret);

    return 0;
}
