// Practical 3: Demonstration of wait() System Call
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        for (int i = 1; i <= 3; i++) {
            printf("Child working %d\n", i);
            sleep(1);
        }
        exit(5);
    } else {
        // parent process
        printf("Parent waiting for child\n");
        pid_t cpid = wait(&status);
        printf("Child %d finished with exit status %d\n", cpid, WEXITSTATUS(status));
    }
    return 0;
}
