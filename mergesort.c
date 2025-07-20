// Program to perform Merge Sort on an array
#include <stdio.h>
#define MAX 100

// Function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[MAX], R[MAX];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    // Merge the temp arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    // Copy the remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];
    // Copy the remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort function
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m); // Sort first half
        mergesort(arr, m + 1, r); // Sort second half
        merge(arr, l, m, r); // Merge the sorted halves
    }
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
    mergesort(arr, 0, n - 1); // Call Merge Sort
    printarray(arr, n);
    return 0;
}