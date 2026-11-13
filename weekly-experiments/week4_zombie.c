#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    char cmd[100];

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child : pid = %d, exiting now\n", getpid());
        exit(0);
    } else {
        sleep(2);   /* parent does not call wait(), so child stays a zombie */
        printf("Parent: pid = %d, child %d has exited but was not waited for\n", getpid(), pid);
        sprintf(cmd, "ps -o pid,ppid,stat,comm -p %d", pid);
        system(cmd);   /* STAT 'Z' means zombie */
    }
    return 0;
}
