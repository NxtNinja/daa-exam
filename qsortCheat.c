#include <stdio.h>
#include <stdlib.h>

int compareInts(const void *a, const void *b) {
    int *x = (int *)a;  // Cast to int pointers
    int *y = (int *)b;
    return *x - *y;  // Sort integers in ascending order (negative for smaller)
}

int main() {
    int numbers[] = {5, 2, 8, 1, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    qsort(numbers, n, sizeof(int), compareInts);

    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
