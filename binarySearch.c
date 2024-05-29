#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // If the key is present at the middle
        if (arr[mid] == key)
            return mid;

        // If the key is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        // Else the key can only be present in the right subarray
        return binarySearch(arr, mid + 1, high, key);
    }

    // Key is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");

    return 0;
}
