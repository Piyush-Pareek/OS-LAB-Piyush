// Practical 2: Parent computes sum of odd numbers, child computes sum of even numbers using fork()
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n, a[100], sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid_t pid = fork();

    if (pid == 0) {
        // child process
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0)
                sum += a[i];
        printf("Child: sum of even numbers = %d\n", sum);
    } else {
        // parent process
        wait(NULL);
        for (int i = 0; i < n; i++)
            if (a[i] % 2 != 0)
                sum += a[i];
        printf("Parent: sum of odd numbers = %d\n", sum);
    }
    return 0;
}
