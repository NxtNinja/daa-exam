#include <stdio.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort: C = "C"rying to see the LOC
void bubbleSort(int arr[], int size) {
    int arrCopy[size];
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arrCopy[i] < arrCopy[j]) {
                int temp = arrCopy[i];
                arrCopy[i] = arrCopy[j];
                arrCopy[j] = temp;
            }
        }
    }
    printArray(arrCopy, size);
}

// Insertion Sort :) eeeeeze peeezeee
void insertionSort(int arr[], int size) {
    int arrCopy[size];
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }
    
    for (int i = 1; i < size; i++) {
        int key = arrCopy[i];
        int j = i - 1;

        while (j >= 0 && arrCopy[j] > key) {
            arrCopy[j + 1] = arrCopy[j];
            j--;
        }
        arrCopy[j + 1] = key;
    }
    printArray(arrCopy, size);
}

// Selection Sort: Uh-Oh Another One
void selectionSort(int arr[], int size) {
    int arrCopy[size];
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arrCopy[j] < arrCopy[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arrCopy[i];
            arrCopy[i] = arrCopy[minIndex];
            arrCopy[minIndex] = temp;
        }
    }
    printArray(arrCopy, size);
}

int main() {
    int arr[] = {45, 741, 47, 22, 34, 52, 1475, 72, 4, 71, 55};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);
    insertionSort(arr, size);
    selectionSort(arr, size);

    return 0;
}
