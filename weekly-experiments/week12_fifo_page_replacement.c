#include <stdio.h>

int main() {
    int n, f, i, j, k, ref[50], frame[10], faults = 0, next = 0, found;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == ref[i])
                found = 1;

        if (!found) {
            frame[next] = ref[i];           /* replace the oldest page */
            next = (next + 1) % f;
            faults++;
        }

        printf("%d\t", ref[i]);
        for (k = 0; k < f; k++) {
            if (frame[k] == -1) printf("-  ");
            else printf("%d  ", frame[k]);
        }
        printf("\t%s\n", found ? "Hit" : "Fault");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits   = %d\n", n - faults);
    return 0;
}
