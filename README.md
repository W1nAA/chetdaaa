# CPE231 Laboratory 2: Experimental Performance Analysis of Sorting Algorithms

## Implemented Algorithms
1. Bubble Sort (O(n^2))
2. Insertion Sort (O(n^2))
3. Selection Sort (O(n^2))
4. Merge Sort (O(nlogn))
5. Quick Sort (O(nlogn))

## Experimental Setup
*   **Input Sizes (n):** 1000, 5000, 10,000, 50,000, 100,000, 200,000
*   **Data Patterns:**
    *   **Random Data:** Randomly generated integers.
    *   **Sorted Data:** Integers arranged in ascending order.
    *   **Reverse-Sorted Data:** Integers arranged in descending order.
*   **Trials:** Each configuration is executed 10 times to calculate the average execution time in milliseconds (ms).

## How to Compile and Run
* Compile

```bash

gcc timing.c -o timing

```
* Run On Linux/macOS

```bash

./timing

```

* Run On Windows

```bash

.\timing.exe

```
