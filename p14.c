// Practical 14 (Additional): fork() and exec() System Calls
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        printf("Child running ls -l using exec\n");
        fflush(stdout);
        execlp("ls", "ls", "-l", NULL);
        printf("exec failed\n");
    } else {
        // parent process
        wait(NULL);
        printf("Parent: child finished\n");
    }
    return 0;
}
