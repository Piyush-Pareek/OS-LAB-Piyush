// Practical 13: Implementation of Least Recently Used (LRU) Page Replacement Algorithm
#include <stdio.h>

int main() {
    int n, f, ref[50], frame[10], last[10], faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ref[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        last[i] = -1;
    }

    printf("\nPage\tFrames\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++)
            if (frame[j] == ref[i]) {
                found = 1;
                last[j] = i;
            }

        if (!found) {
            int pos = 0;
            for (int j = 1; j < f; j++)
                if (last[j] < last[pos])
                    pos = j;
            frame[pos] = ref[i];
            last[pos] = i;
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
