// Practical 6: Implementation of FIFO / Named Pipe
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    char *fifo = "/tmp/myfifo";
    char msg[] = "Hello through FIFO";
    char buf[100];

    mkfifo(fifo, 0666);
    pid_t pid = fork();

    if (pid == 0) {
        // child process (reader)
        int fd = open(fifo, O_RDONLY);
        read(fd, buf, sizeof(buf));
        printf("Reader received: %s\n", buf);
        close(fd);
    } else {
        // parent process (writer)
        int fd = open(fifo, O_WRONLY);
        write(fd, msg, strlen(msg) + 1);
        printf("Writer sent: %s\n", msg);
        close(fd);
        wait(NULL);
        unlink(fifo);
    }
    return 0;
}
