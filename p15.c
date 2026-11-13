// Practical 15 (Additional): Implementation of Unix Pipeline: ls | wc
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // first child runs ls
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", NULL);
    }

    if (fork() == 0) {
        // second child runs wc
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
