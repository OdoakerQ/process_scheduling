#include <stdio.h>
#include <lib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid;
    int currPid = getpid();
    int ret;
    message m1;

    pid = atoi(argv[1]);
    m1.m1_i1 = pid;

    if (argc != 2) {
    	printf("Wrong args number: %d\n", argc);
    	exit(1);
    }
    printf("PID: %d\n", currPid);
    ret = _syscall( MM_PROC_NR, GETGPROC, &m1 );
    printf("%d\n", ret);

    return 0;
}
