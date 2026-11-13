#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, cpid;
    int status, i;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child (pid %d) started\n", getpid());
        for (i = 1; i <= 3; i++) {
            printf("Child working... %d\n", i);
            sleep(1);
        }
        printf("Child finished\n");
        exit(5);
    } else {
        printf("Parent (pid %d) waiting for child to finish...\n", getpid());
        cpid = wait(&status);
        printf("Parent: child %d terminated\n", cpid);
        if (WIFEXITED(status))
            printf("Parent: child exit status = %d\n", WEXITSTATUS(status));
    }
    return 0;
}
