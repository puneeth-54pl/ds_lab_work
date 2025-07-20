#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Value %d inserted at end.\n", value);
}

void display() {
    if (head == NULL) {
        printf("\nCircular Linked List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("\nCircular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void showMenu() {
    printf("\nCircular Linked List Menu:\n");
    printf("1. Insert at end\n");
    printf("2. Display list\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

int main() {
    int choice, value;
    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
