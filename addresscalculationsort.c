// Program to perform Address Calculation Sort (Bucket Sort style)
#include <stdio.h>
#define MAX 100
#define BUCKETS 10

// Function to perform Address Calculation Sort
void addressCalculationSort(int arr[], int n) {
    int buckets[BUCKETS][MAX]; // Buckets for sorting
    int count[BUCKETS] = {0}; // Count of elements in each bucket
    // Distribute elements into buckets based on address calculation
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10; // Simple address calculation
        if (index >= BUCKETS) index = BUCKETS - 1;
        buckets[index][count[index]++] = arr[i];
    }
    int k = 0;
    // Collect elements from buckets back into the array
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
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
    addressCalculationSort(arr, n); // Call Address Calculation Sort
    printarray(arr, n);
    return 0;
}
    
