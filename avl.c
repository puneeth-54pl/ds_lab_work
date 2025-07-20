// Program to implement an AVL Tree with insert, traversals, and height calculation
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node* NODEPTR;

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get height of the tree
int height(NODEPTR N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to create a new AVL tree node
NODEPTR newNode(int key) {
    NODEPTR node = (NODEPTR)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate subtree rooted with y
NODEPTR rightRotate(NODEPTR y) {
    NODEPTR x = y->left;
    NODEPTR T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Function to left rotate subtree rooted with x
NODEPTR leftRotate(NODEPTR x) {
    NODEPTR y = x->right;
    NODEPTR T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Function to get balance factor of node N
int getBalance(NODEPTR N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Function to insert a key into the AVL tree
NODEPTR insert(NODEPTR node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// Function for preorder traversal
void preOrder(NODEPTR root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for inorder traversal
void inOrder(NODEPTR root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function for postorder traversal
void postOrder(NODEPTR root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

// Function to find the height of the AVL tree
int findHeight(NODEPTR root) {
    if (root == NULL)
        return 0;
    int lheight = findHeight(root->left);
    int rheight = findHeight(root->right);
    return 1 + (lheight > rheight ? lheight : rheight);
}

// Function to display the menu
void showMenu() {
    printf("\nAVL Tree Menu:\n");
    printf("1. Insert element\n");
    printf("2. Preorder traversal\n");
    printf("3. Inorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Find height\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
}

int main() {
    NODEPTR root = NULL;
    int choice, key;
    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d into AVL tree.\n", key);
                break;
            case 2:
                printf("Preorder traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Height of AVL tree: %d\n", findHeight(root));
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}