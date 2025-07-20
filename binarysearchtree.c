#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node* NODEPTR;

NODEPTR getnode(int x) {
    NODEPTR p = (NODEPTR)malloc(sizeof(struct node));
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
NODEPTR insert(NODEPTR root,int x){
if(root==NULL){
    return getnode(x);

}
if(x<root->info){
    root->left=insert(root->left,x);
}
else if(x>root->info){
    root->right=insert(root->right,x);

}
return root;
}
void inorder(NODEPTR p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->info);
        inorder(p->right);
    }
}

int main() {
    NODEPTR root=NULL;
    int n,num;

    printf("Enter the number of elements to insert into bst:");
    scanf("%d",&n);
    printf("enter the numbers:");

    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert(root,num);
    }
    printf("\nSorted BST using Inorder traversal: ");
    inorder(root);


    return 0;
}
