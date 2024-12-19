#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *lchild, *rchild;
};
typedef struct BST * NODE;

NODE create() {
    NODE temp = (NODE) malloc(sizeof(struct BST));
    scanf("%d", &temp->data);
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void insert(NODE root, NODE newnode) {
    if (newnode->data < root->data) 
        root->lchild ? insert(root->lchild, newnode) : (root->lchild = newnode);
    if (newnode->data > root->data) 
        root->rchild ? insert(root->rchild, newnode) : (root->rchild = newnode);
}

void inorder(NODE root) {
    if (root)
        inorder(root->lchild); printf("%d ", root->data); inorder(root->rchild);
}

void preorder(NODE root) { 
    if (root)
        printf("%d ", root->data); preorder(root->lchild); preorder(root->rchild);
}

void postorder(NODE root) { 
    if (root)
        postorder(root->lchild); postorder(root->rchild); printf("%d ", root->data);
}

void search(NODE root, int key) {
    while (root) {
        if (root->data == key) { printf("Found\n"); return; }
        root = key < root->data ? root->lchild : root->rchild;
    }
    printf("Not Found\n");
}

int main() {
    int ch, n, i, key;
    NODE root = NULL, newnode;
    while (1) {
        printf("\n1. Create BST\n2. Traversals\n3. Search\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: 
                printf("Enter number of elements: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    newnode = create();
                    root ? insert(root, newnode) : (root = newnode);
                }
                break;
            case 2: 
                if (root) {
                    printf("Preorder: "); preorder(root); printf("\nInorder: "); inorder(root); printf("\nPostorder: "); postorder(root);
                } else printf("Tree is empty\n");
                break;
            case 3: 
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 4: exit(0);
        }
    }
}