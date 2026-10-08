#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 5;
    pid_t pid = fork();

    if (pid == 0) {
        int a = 0, b = 1, next;
        printf("Fibonacci: ");
        for (int i = 1; i <= n; i++) {
            printf("%d ", a);
            next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
        exit(0);
    } else {
        wait(NULL);
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        printf("Factorial: %d\n", fact);
    }
    return 0;
}