#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char msg[] = "Hello child, this message is sent through a pipe";
    char buf[100];
    pid_t pid;

    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        close(fd[1]);                       /* child only reads */
        read(fd[0], buf, sizeof(buf));
        printf("Child  received: %s\n", buf);
        close(fd[0]);
    } else {
        close(fd[0]);                       /* parent only writes */
        printf("Parent writing : %s\n", msg);
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
