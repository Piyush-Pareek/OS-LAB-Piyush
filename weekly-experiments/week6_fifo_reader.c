#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifo = "/tmp/myfifo";
    char buf[100];

    mkfifo(fifo, 0666);

    fd = open(fifo, O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("Reader: message received -> %s\n", buf);
    close(fd);
    unlink(fifo);                       /* remove the FIFO file */
    return 0;
}
