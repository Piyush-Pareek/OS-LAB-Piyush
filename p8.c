// Practical 8: Implementation of Shared Memory
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    key_t key = ftok("/tmp", 66);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    pid_t pid = fork();

    if (pid == 0) {
        // child process (writer)
        char *str = (char *) shmat(shmid, NULL, 0);
        strcpy(str, "Hello through shared memory");
        printf("Writer wrote: %s\n", str);
        shmdt(str);
    } else {
        // parent process (reader)
        wait(NULL);
        char *str = (char *) shmat(shmid, NULL, 0);
        printf("Reader read: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
