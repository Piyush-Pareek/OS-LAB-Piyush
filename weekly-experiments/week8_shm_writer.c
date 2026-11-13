#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key;
    int shmid;
    char *str;

    key = ftok("/tmp", 66);
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);  /* create 1 KB segment */
    str = (char *) shmat(shmid, NULL, 0);         /* attach */

    strcpy(str, "Hello from writer through shared memory");
    printf("Writer: data written to shared memory -> %s\n", str);

    shmdt(str);                                   /* detach */
    return 0;
}
