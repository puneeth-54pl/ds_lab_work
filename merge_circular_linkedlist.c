#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createCircularList(int n) {
    if (n <= 0) return NULL;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;
    return head;
}

void displayCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");
}

struct Node* mergeCircularLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    struct Node *temp1 = head1, *temp2 = head2;
    while (temp1->next != head1) temp1 = temp1->next;
    while (temp2->next != head2) temp2 = temp2->next;

    temp1->next = head2;
    temp2->next = head1;
    return head1;
}

int main() {
    int n1, n2;
    printf("Enter number of nodes for first circular linked list: ");
    scanf("%d", &n1);
    struct Node* head1 = createCircularList(n1);
    printf("\nEnter number of nodes for second circular linked list: ");
    scanf("%d", &n2);
    struct Node* head2 = createCircularList(n2);
    printf("\nFirst List: ");
    displayCircularList(head1);
    printf("Second List: ");
    displayCircularList(head2);
    struct Node* merged = mergeCircularLists(head1, head2);
    printf("\nMerged Circular Linked List: ");
    displayCircularList(merged);
    return 0;
}
