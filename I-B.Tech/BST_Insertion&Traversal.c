//Binary Search Tree Insertion and Traversal-Preorder,Inorder,postorder
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insertNode(struct node *root, int value) {
    if (root == NULL) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        printf("Inserted element into BST is: %d\n", newNode->data);
        return newNode;
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } 
	else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void main() {
    int choice, value;
    struct node *root = NULL;
    while (1) {
        printf("\n1. Exit\n");
        printf("2. Insert a new node in the Binary Tree\n");
        printf("3. Display nodes via Inorder Traversal\n");
        printf("4. Display nodes via Preorder Traversal\n");
        printf("5. Display nodes via Postorder Traversal\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                exit(0);
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    
}
