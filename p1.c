// Practical 1: Demonstration of fork() System Call
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before fork, pid = %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    } else if (pid == 0) {
        // child process
        printf("Child: pid = %d, parent pid = %d\n", getpid(), getppid());
    } else {
        // parent process
        sleep(1);
        printf("Parent: pid = %d, child pid = %d\n", getpid(), pid);
    }
    return 0;
}
