//Stack Implementation Using Linkedlist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void display() 
{

    if (top == NULL) 
	{
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Elements in stack are: ");
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void push() 
{
	int value;
	printf("Enter elem value to push: ");scanf("%d",&value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("Element %d pushed to stack.\n", value);
}

void pop() {

    if (top == NULL) {
        printf("Underflow, Stack is empty. Nothing to pop.\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);

    printf("Element %d popped from stack.\n", top->data);
}


void peek()
{
    if (top == NULL) 
	{
        printf("Underflow condition, Stack is empty.\n");
        return;
    }
    printf("Top element of the stack is: %d\n", top->data);
}

void main() 
{
    int choice;
    while (1) 
	{
        printf("\n1. Exit\n2. Display\n3. Push\n4. Pop\n5.Peek \nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:exit(0);
            case 2:display();break;
            case 3:push();break;
            case 4:pop();break;
            case 5:peek();break;
            default:printf("Invalid choice.\n");
                
        }
    }
}
