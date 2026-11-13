#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Before fork: process id = %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process : pid = %d, parent pid = %d\n", getpid(), getppid());
    } else {
        sleep(1);
        printf("Parent process: pid = %d, child pid = %d\n", getpid(), pid);
    }
    return 0;
}
