#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swap = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap = 1;
            }
        }

        if (swap == 0) {
            break;
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void merge(int a[], int left, int mid, int right) {
    int size = right - left +1;
    int *temp = (int *)malloc(size * sizeof(int));
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        a[left + i] = temp[i];
    }
    free(temp);
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int partition(int a[], int low, int high) {
    int mid = low + (high - low) / 2;
    int swap_temp = a[mid];
    a[mid] = a[high];
    a[high] = swap_temp;

    int pivot = a[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }

    int temp = a[i];
    a[i] = a[high];
    a[high] = temp;

    return i;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void mergeSortWrapper(int a[], int n) {
    if (n > 0) {
        mergeSort(a, 0, n - 1);
    }
}

void quickSortWrapper(int a[], int n) {
    if (n > 0) {
        quickSort(a, 0, n - 1);
    }
}

void generateDataset(int arr[], int n, int pattern) {
    for (int i = 0; i < n; i++) {
        if (pattern == 0){
            arr[i] = rand() % 100000; // Random Data
        }
        else if (pattern == 1){
            arr[i] = i; // Sorted Data
        }
        else if (pattern == 2) {
            arr[i] = n - i; // Reverse-Sorted Data
        }
    }
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000, 100000, 200000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    int trials = 10;
    
    char *patternNames[] = {"Random", "Sorted", "Reverse-Sorted"};
    char *algoNames[] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort"};
    
    void (*sortingAlgorithms[])(int[], int) = {
        bubbleSort, insertionSort, selectionSort, mergeSortWrapper, quickSortWrapper
    };
    int numAlgos = 5;

    srand(42); // Set Seed

    // Input Size
    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        int *masterDataset = (int *)malloc(n * sizeof(int));
        int *testArray = (int *)malloc(n * sizeof(int));

        printf("\n=========================\n");
        printf("Testing Input Size: %d", n);
        printf("\n=========================\n");

        // Input Pattern
        for (int p = 0; p < 3; p++) {
            generateDataset(masterDataset, n, p);
            printf("***** Pattern: %s *****\n", patternNames[p]);

            // Sorting Algorithm
            for (int a = 0; a < numAlgos; a++) {
                double totalTime_ms = 0.0;
                printf("====================\n");
                printf("%s\n", algoNames[a]);
                printf("====================\n");

                // Trials
                for (int t = 0; t < trials; t++) {
                    memcpy(testArray, masterDataset, n * sizeof(int));

                    struct timespec start, end;
                    clock_gettime(CLOCK_MONOTONIC, &start);

                    sortingAlgorithms[a](testArray, n);

                    clock_gettime(CLOCK_MONOTONIC, &end);

                    double time_taken = (end.tv_sec - start.tv_sec) * 1000.0;
                    time_taken += (end.tv_nsec - start.tv_nsec) / 1000000.0;
                    totalTime_ms += time_taken;

                    printf("[Trial %d: %.4f ms]\n", t+1, time_taken);
                }

                double averageTime_ms = totalTime_ms / trials;
                printf("--------------------\n");
                printf("Avg: %.4f ms\n", averageTime_ms);
                printf("--------------------\n");
            }
        }
        free(testArray);
        free(masterDataset);
    }
    return 0;
}