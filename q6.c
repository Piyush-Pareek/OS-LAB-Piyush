#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void armstrong(int n) {
    printf("Armstrong up to %d: ", n);
    for (int i = 1; i <= n; i++) {
        int sum = 0, temp = i, rem;
        while (temp > 0) {
            rem = temp % 10;
            sum = sum + (rem * rem * rem);
            temp = temp / 10;
        }
        if (sum == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n = 155;
    pid_t pid = fork();

    if (pid == 0) {
        fibonacci(7);
        exit(0);
    } else {
        wait(NULL);
        armstrong(n);
    }
    return 0;
}