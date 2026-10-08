#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 == 0) {
        pid_t pid2 = fork();
        
        if (pid2 == 0) {
            printf("Dada PID: %d\n", getpid());
            exit(0);
        } else {
            wait(NULL);
            printf("Child PID: %d\n", getpid());
            exit(0);
        }
    } else {
        wait(NULL);
        printf("Parent PID: %d\n", getpid());
    }
    return 0;
}