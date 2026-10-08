#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int arr[] = {3, 5, 2, 1};
    pipe(fd);
    
    pid_t pid = fork();

    if (pid == 0) {
        close(fd[0]);
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum = sum + arr[i];
        }
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        exit(0);
    } else {
        close(fd[1]);
        int received_sum;
        read(fd[0], &received_sum, sizeof(received_sum));
        
        int isPrime = 1;
        if (received_sum <= 1) isPrime = 0;
        for (int i = 2; i <= received_sum / 2; i++) {
            if (received_sum % i == 0) {
                isPrime = 0;
                break;
            }
        }
        
        if (isPrime) {
            printf("Sum %d is Prime\n", received_sum);
        } else {
            printf("Sum %d is Not Prime\n", received_sum);
        }
        
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}