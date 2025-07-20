#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node* NODEPTR;

NODEPTR getnode() {
    NODEPTR p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

NODEPTR maketree(int x) {
    NODEPTR p = getnode();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

NODEPTR buildtree() {
    int x;
    printf("Enter value (-1 for NULL): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    NODEPTR p = maketree(x);

    printf("Enter left child of %d:\n", x);
    p->left = buildtree();

    printf("Enter right child of %d:\n", x);
    p->right = buildtree();

    return p;
}

void inorder(NODEPTR p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->info);
        inorder(p->right);
    }
}

void preorder(NODEPTR p) {
    if (p != NULL) {
        printf("%d ", p->info);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(NODEPTR p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->info);
    }
}

int main() {
    NODEPTR root;

    printf("Build the binary tree:\n");
    root = buildtree();

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}
