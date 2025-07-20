// Program to perform Quick Sort on an array
#include <stdio.h>
#define MAX 100

// Partition function for Quick Sort
void partition(int x[], int lb, int ub, int *pj) {
    int a, down, temp, up;
    a = x[lb]; // Choose the first element as pivot
    up = ub;
    down = lb;
    while (down < up) {
        // Move down pointer to the right as long as elements are <= pivot
        while (x[down] <= a && down < up)
            down++;
        // Move up pointer to the left as long as elements are > pivot
        while (x[up] > a)
            up--;
        // Swap if down is still less than up
        if (down < up) {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    // Place pivot in its correct position
    x[lb] = x[up];
    x[up] = a;
    *pj = up;
}

// Recursive Quick Sort function
void quick(int x[], int lb, int ub) {
    int j;
    if (lb >= ub)
        return;
    partition(x, lb, ub, &j);
    quick(x, lb, j - 1); // Sort left part
    quick(x, j + 1, ub); // Sort right part
}

// Function to print the array
void printarray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick(arr, 0, n - 1); // Call Quick Sort
    printarray(arr, n);
    return 0;
}
