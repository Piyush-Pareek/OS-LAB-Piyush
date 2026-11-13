#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Implements the shell command:  ls | wc  */
int main() {
    int fd[2];

    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        return 1;
    }

    if (fork() == 0) {
        /* first child: ls, output goes into the pipe */
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", NULL);
        exit(1);
    }

    if (fork() == 0) {
        /* second child: wc, input comes from the pipe */
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    printf("Output above = lines, words, characters of 'ls' (same as running ls | wc)\n");
    return 0;
}
