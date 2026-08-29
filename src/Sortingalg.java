import java.util.Arrays;

public class Main {

    public static void bubbleSort(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            boolean check = false;

            for (int j = 0; j < a.length - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    check = true;
                }
            }

            if (!check) {
                break;
            }
        }
    }

    public static void insertionSort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int num = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > num) {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = num;
        }
    }

    public static void selectionSort(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            int min = i;

            for (int j = i + 1; j < a.length; j++) {
                if (a[j] < a[min]) {
                    min = j;
                }
            }

            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    public static void mergeSort(int[] a, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSort(a, left, mid);
            mergeSort(a, mid + 1, right);

            merge(a, left, mid, right);
        }
    }

    public static void merge(int[] a, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];

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
            temp[k++] = a[i++];
        }

        while (j <= right) {
            temp[k++] = a[j++];
        }

        for (i = 0; i < temp.length; i++) {
            a[left + i] = temp[i];
        }
    }

    public static void quickSort(int[] a, int low, int high) {
        if (low < high) {
            int p = partition(a, low, high);

            quickSort(a, low, p - 1);
            quickSort(a, p + 1, high);
        }
    }

    public static int partition(int[] a, int low, int high) {
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

    public static void main(String[] args) {

        int[] data = {50, 20, 40, 10, 30};

        int[] a1 = data.clone();
        bubbleSort(a1);
        System.out.println("Bubble Sort = " + Arrays.toString(a1));

        int[] a2 = data.clone();
        insertionSort(a2);
        System.out.println("Insertion Sort = " + Arrays.toString(a2));

        int[] a3 = data.clone();
        selectionSort(a3);
        System.out.println("Selection Sort = " + Arrays.toString(a3));

        int[] a4 = data.clone();
        mergeSort(a4, 0, a4.length - 1);
        System.out.println("Merge Sort = " + Arrays.toString(a4));

        int[] a5 = data.clone();
        quickSort(a5, 0, a5.length - 1);
        System.out.println("Quick Sort = " + Arrays.toString(a5));
    }
}
