#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child : pid = %d, parent pid = %d (before parent exits)\n", getpid(), getppid());
        sleep(3);   /* parent exits during this time */
        printf("Child : pid = %d, parent pid = %d (after parent exits - ORPHAN, adopted by init)\n",
               getpid(), getppid());
    } else {
        printf("Parent: pid = %d, exiting now without waiting for child\n", getpid());
    }
    return 0;
}
