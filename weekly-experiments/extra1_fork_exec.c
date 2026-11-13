#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child (pid %d): replacing itself with 'ls -l' using exec\n", getpid());
        fflush(stdout);
        execlp("ls", "ls", "-l", NULL);
        printf("This line runs only if exec fails\n");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent (pid %d): child finished executing ls\n", getpid());
    }
    return 0;
}
