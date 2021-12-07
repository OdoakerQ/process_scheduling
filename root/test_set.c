#include <stdio.h>
#include <lib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid;
    int newGroup;
    int currPid = getpid();
    int ret;
    message m1, m2;

    pid = atoi(argv[1]);
    newGroup = atoi(argv[2]);
    m1.m1_i1 = pid;
    m1.m1_i2 = newGroup;

    if (argc != 3) {
    	printf("Wrong args number: %d\n", argc);
    	exit(1);
    }

    printf("PID: %d\n", currPid);
    ret = _syscall( MM_PROC_NR, SETGPROC, &m1 );
    printf("%d\n", ret);

    return 0;
}
