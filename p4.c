// Practical 4: Implementation of Orphan Process and Zombie Process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char cmd[50];

    pid_t pid1 = fork();
    if (pid1 == 0) {
        // child exits, parent does not wait -> zombie
        exit(0);
    }
    sleep(1);
    printf("Zombie process:\n");
    sprintf(cmd, "ps -o pid,ppid,stat,comm -p %d", pid1);
    system(cmd);

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // child keeps running after parent exits -> orphan
        printf("\nOrphan process:\n");
        printf("Child pid = %d, parent pid = %d\n", getpid(), getppid());
        sleep(2);
        printf("Child pid = %d, new parent pid = %d\n", getpid(), getppid());
        exit(0);
    }
    sleep(1);
    printf("Parent exiting\n");
    return 0;
}
