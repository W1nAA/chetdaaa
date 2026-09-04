#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

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
    int temp[100];
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
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

// Quick Sort
int partition(int a[], int low, int high) {
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

int main() {

    int data[] = {50, 20, 40, 10, 30};
    int n = 5;

    // Bubble Sort
    int a1[] = {50, 20, 40, 10, 30};
    bubbleSort(a1, n);
    printf("Bubble Sort:    ");
    printArray(a1, n);

    int a2[] = {50, 20, 40, 10, 30};
    insertionSort(a2, n);
    printf("Insertion Sort: ");
    printArray(a2, n);

    int a3[] = {50, 20, 40, 10, 30};
    selectionSort(a3, n);
    printf("Selection Sort: ");
    printArray(a3, n);

    int a4[] = {50, 20, 40, 10, 30};
    mergeSort(a4, 0, n - 1);
    printf("Merge Sort:     ");
    printArray(a4, n);

    int a5[] = {50, 20, 40, 10, 30};
    quickSort(a5, 0, n - 1);
    printf("Quick Sort:     ");
    printArray(a5, n);

    return 0;
}
