#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifo = "/tmp/myfifo";
    char msg[] = "Hello from writer process through FIFO";

    mkfifo(fifo, 0666);                 /* create named pipe */

    fd = open(fifo, O_WRONLY);          /* waits until reader opens */
    write(fd, msg, strlen(msg) + 1);
    printf("Writer: message sent -> %s\n", msg);
    close(fd);
    return 0;
}
