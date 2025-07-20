// Program to demonstrate various sorting algorithms: Selection, Insertion, and Shell Sort
#include <stdio.h>
#define MAX 100

// Function to perform Selection Sort
void selectsort(int arr[], int n) {
    // Move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // Find the minimum element in unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    printf("Array sorted using Selection Sort.\n");
}

// Function to perform Insertion Sort
void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Array sorted using Insertion Sort.\n");
}

// Function to perform Shell Sort
void shellsort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("Array sorted using Shell Sort.\n");
}

// Function to print the array
void printarray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display the menu
void showMenu() {
    printf("\nSorting Menu:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Shell Sort\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main() {
    int arr[MAX], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                selectsort(arr, n); // Selection Sort
                printarray(arr, n);
                break;
            case 2:
                insertionsort(arr, n); // Insertion Sort
                printarray(arr, n);
                break;
            case 3:
                shellsort(arr, n); // Shell Sort
                printarray(arr, n);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}