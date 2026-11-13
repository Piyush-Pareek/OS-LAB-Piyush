// Practical 12: Implementation of FIFO Page Replacement Algorithm
#include <stdio.h>

int main() {
    int n, f, ref[50], frame[10], faults = 0, next = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ref[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++)
            if (frame[j] == ref[i])
                found = 1;

        if (!found) {
            frame[next] = ref[i];
            next = (next + 1) % f;
            faults++;
        }

        printf("%d\t", ref[i]);
        for (int j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf(found ? "\tHit\n" : "\tFault\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
