#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, i, a[100], sum = 0;
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        for (i = 0; i < n; i++)
            if (a[i] % 2 == 0)
                sum += a[i];
        printf("Child  (pid %d): Sum of even numbers = %d\n", getpid(), sum);
    } else {
        wait(NULL);
        for (i = 0; i < n; i++)
            if (a[i] % 2 != 0)
                sum += a[i];
        printf("Parent (pid %d): Sum of odd numbers  = %d\n", getpid(), sum);
    }
    return 0;
}
