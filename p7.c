// Practical 7: Implementation of Message Queue
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct message {
    long type;
    char text[100];
};

int main() {
    struct message m;
    key_t key = ftok("/tmp", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    pid_t pid = fork();

    if (pid == 0) {
        // child process (sender)
        m.type = 1;
        strcpy(m.text, "Hello through message queue");
        msgsnd(msgid, &m, sizeof(m.text), 0);
        printf("Sender sent: %s\n", m.text);
    } else {
        // parent process (receiver)
        wait(NULL);
        msgrcv(msgid, &m, sizeof(m.text), 1, 0);
        printf("Receiver received: %s\n", m.text);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}
