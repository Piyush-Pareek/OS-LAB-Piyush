#include <stdio.h>
#include <string.h>
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

    key = ftok("/tmp", 65);                       /* unique key */
    msgid = msgget(key, 0666 | IPC_CREAT);        /* create queue */

    m.type = 1;
    strcpy(m.text, "Hello from sender through message queue");

    msgsnd(msgid, &m, sizeof(m.text), 0);
    printf("Sender  : message sent    -> %s\n", m.text);
    return 0;
}
