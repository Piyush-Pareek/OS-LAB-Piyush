#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key;
    int shmid;
    char *str;

    key = ftok("/tmp", 66);
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    str = (char *) shmat(shmid, NULL, 0);

    printf("Reader: data read from shared memory  -> %s\n", str);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);                /* destroy segment */
    return 0;
}
