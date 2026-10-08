#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 5;
    pid_t pid = fork();

    if (pid == 0) {
        int isPrime = 1;
        if (n <= 1) isPrime = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("Child %d: %d is Prime\n", getpid(), n);
        } else {
            printf("Child %d: %d is Not Prime\n", getpid(), n);
        }
        exit(0);
    } else {
        wait(NULL);
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        printf("Parent %d Child ID %d: Factorial is %d\n", getpid(), pid, fact);
    }
    return 0;
}