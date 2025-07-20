// Program to construct a Binary Search Tree (BST) and perform inorder traversal
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node* NODEPTR;

// Function to allocate a new node with value x
NODEPTR getnode(int x) {
    NODEPTR p = (NODEPTR)malloc(sizeof(struct node));
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Function to insert a value into the BST
NODEPTR insert(NODEPTR root, int x) {
    if (root == NULL) {
        return getnode(x);
    }
    if (x < root->info) {
        root->left = insert(root->left, x);
    } else if (x > root->info) {
        root->right = insert(root->right, x);
    }
    return root;
}

// Function for inorder traversal of BST
void inorder(NODEPTR p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->info);
        inorder(p->right);
    }
}

int main() {
    NODEPTR root = NULL;
    int n, num;
    printf("Enter the number of elements to insert into bst: ");
    scanf("%d", &n);
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        root = insert(root, num);
    }
    printf("\nSorted BST using Inorder traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}
