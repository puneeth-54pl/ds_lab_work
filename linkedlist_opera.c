// Program to implement a Linked List with various operations (insert at beginning, end, before, at position, display)
#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct Node {
    int data;
    int next;
};

struct Node list[SIZE]; // Array to store nodes
int head = -1;          // Index of the head node
int avail = 0;          // Index of the first available node

// Function to initialize the linked list and free list
void initialize() {
    for (int i = 0; i < SIZE - 1; i++) {
        list[i].next = i + 1;
    }
    list[SIZE - 1].next = -1;
    head = -1;
    avail = 0;
}

// Function to get a free node from the free list
int getnode() {
    if (avail == -1) {
        printf("Overflow! No space available.\n");
        return -1;
    }
    int p = avail;
    avail = list[avail].next;
    return p;
}

// Function to free a node and add it back to the free list
void freenode(int p) {
    list[p].next = avail;
    avail = p;
}

// Function to insert a value at the beginning of the list
void insertBeginning(int value) {
    int newNode = getnode();
    if (newNode == -1)
        return;
    list[newNode].data = value;
    list[newNode].next = head;
    head = newNode;
    printf("Value %d inserted at beginning.\n", value);
}

// Function to insert a value at the end of the list
void insertEnd(int value) {
    int newNode = getnode();
    if (newNode == -1)
        return;
    list[newNode].data = value;
    list[newNode].next = -1;
    if (head == -1) {
        head = newNode;
    } else {
        int temp = head;
        while (list[temp].next != -1)
            temp = list[temp].next;
        list[temp].next = newNode;
    }
    printf("Value %d inserted at end.\n", value);
}

// Function to insert a value before a given key
void insertBefore(int key, int value) {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }
    int newNode = getnode();
    if (newNode == -1)
        return;
    list[newNode].data = value;
    if (list[head].data == key) {
        list[newNode].next = head;
        head = newNode;
        printf("Value %d inserted before %d.\n", value, key);
        return;
    }
    int prev = head, curr = list[head].next;
    while (curr != -1 && list[curr].data != key) {
        prev = curr;
        curr = list[curr].next;
    }
    if (curr == -1) {
        printf("Key not found in the list.\n");
        freenode(newNode);
        return;
    }
    list[newNode].next = curr;
    list[prev].next = newNode;
    printf("Value %d inserted before %d.\n", value, key);
}

// Function to insert a value at a given position
void insertAtPosition(int pos, int value) {
    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }
    int newNode = getnode();
    if (newNode == -1)
        return;
    list[newNode].data = value;
    if (pos == 0) {
        list[newNode].next = head;
        head = newNode;
        printf("Value %d inserted at position 0.\n", value);
        return;
    }
    int count = 0, curr = head;
    while (count < pos - 1 && curr != -1) {
        curr = list[curr].next;
        count++;
    }
    if (curr == -1) {
        printf("Position out of bounds.\n");
        freenode(newNode);
        return;
    }
    list[newNode].next = list[curr].next;
    list[curr].next = newNode;
    printf("Value %d inserted at position %d.\n", value, pos);
}

// Function to display the linked list
void display() {
    if (head == -1) {
        printf("\nLinked List is empty\n");
        return;
    }
    int temp = head;
    printf("\nLinked List: ");
    while (temp != -1) {
        printf("%d -> ", list[temp].data);
        temp = list[temp].next;
    }
    printf("NULL\n");
}

// Function to display the menu
void showMenu() {
    printf("\nLinked List Operations Menu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert before a value\n");
    printf("4. Insert at position\n");
    printf("5. Display list\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
}

int main() {
    initialize();
    int choice, value, key, pos;
    do {
        clrscr();
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter key value to insert before: ");
                scanf("%d", &key);
                insertBefore(key, value);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insertAtPosition(pos, value);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        printf("\nPress any key to continue...");
        getch();
    } while (choice != 6);
    return 0;
}
