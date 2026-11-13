// Practical 5: Implementation of Pipe
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char msg[] = "Hello from parent";
    char buf[100];

    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(fd[0]);
    } else {
        // parent process
        close(fd[0]);
        write(fd[1], msg, strlen(msg) + 1);
        printf("Parent sent: %s\n", msg);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
