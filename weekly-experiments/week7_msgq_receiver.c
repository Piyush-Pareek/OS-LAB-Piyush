#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long type;
    char text[100];
};

int main() {
    key_t key;
    int msgid;
    struct message m;

    key = ftok("/tmp", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &m, sizeof(m.text), 1, 0);      /* receive type 1 message */
    printf("Receiver: message received -> %s\n", m.text);

    msgctl(msgid, IPC_RMID, NULL);                /* delete the queue */
    return 0;
}
