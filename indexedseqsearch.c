// Program to perform Indexed Sequential Search on a sorted array
#include <stdio.h>
#define MAX 100
#define INDEX_SIZE 10

// Structure for index table
struct IndexEntry {
    int key; // Key value at the start of each block
    int pos; // Position in the array
};

// Function to create the index table for the array
void createIndex(int arr[], int n, struct IndexEntry index[], int *indexCount) {
    int step = n / INDEX_SIZE;
    if (step == 0) step = 1;
    int j = 0;
    for (int i = 0; i < n; i += step) {
        index[j].key = arr[i];
        index[j].pos = i;
        j++;
    }
    *indexCount = j;
}

// Function to perform indexed sequential search
int indexedSequentialSearch(int arr[], int n, struct IndexEntry index[], int indexCount, int key) {
    int i;
    // Find the block where the key may be present
    for (i = 0; i < indexCount && key > index[i].key; i++);
    int start = (i == 0) ? 0 : index[i-1].pos;
    int end = (i < indexCount) ? index[i].pos : n;
    // Linear search within the block
    for (int j = start; j < end; j++) {
        if (arr[j] == key)
            return j;
    }
    return -1;
}

// Function to print the array
void printarray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n, key, pos;
    struct IndexEntry index[INDEX_SIZE];
    int indexCount;
    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    createIndex(arr, n, index, &indexCount); // Create index table
    printf("Enter key to search: ");
    scanf("%d", &key);
    pos = indexedSequentialSearch(arr, n, index, indexCount, key); // Search for key
    if (pos != -1)
        printf("Key %d found at position %d.\n", key, pos);
    else
        printf("Key %d not found.\n", key);
    return 0;
} 