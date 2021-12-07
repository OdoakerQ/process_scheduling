#include <stdio.h>
#include <lib.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    int j;
    int ret, ret2;
    int group;
    int pid;
    message m1, m2, m3;

    if (argc != 2) {
    	printf("Wrong args number: %d\n", argc);
    	exit(1);
    }

    group = atoi(argv[1]);
    pid = getpid();
    m1.m1_i1 = pid;
    m1.m1_i2 = group;
    m2.m1_i1 = group;
    m3.m1_i1 = pid;
    ret = _syscall( MM_PROC_NR, SETGPROC, &m1 );
    if (ret != 0) {
        printf("PROC setgproc did not work.\n");
        exit(-1);
    }
    ret = _syscall( MM_PROC_NR, GETGPARAM, &m2 );
    ret2 = _syscall( MM_PROC_NR, GETGPROC, &m3 );
    printf("PROC: pid: %d, param: %d, group %d\n", pid, ret, ret2);

    for(i = 0; i <100; i++) {
        for(j = 0; j < 9999999; j++) {

        }
    }
    printf("%d ENDED\n", pid); 

    return 0;
}
