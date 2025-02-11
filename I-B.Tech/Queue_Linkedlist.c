//Queue Implementation Using Linkedlist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void display() 
{

    if (front == NULL && rear==NULL) 
	{
        printf("Queue is empty.\n");
        return;
    }
    else
	{
	
	    struct Node* temp = front;
	    printf("Elements in Queue are: ");
	    while (temp != NULL) 
		{
	        printf("%d ", temp->data);
	        temp = temp->next;
	    }
	    printf("\t");
	}
}
void enqueue() 
{
	int value;
	printf("Enter elem value to insert: ");scanf("%d",&value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    printf("Element %d inserted to queue.\n", value);
    if(front==NULL && rear==NULL) front=rear=newNode;
    else
	{
		rear->next=newNode;rear=newNode;
	 } 
}

void dequeue() {

    if (front == NULL) 
        printf("Underflow, Queue is empty. Nothing to pop.\n");
    else
	{
    struct Node* temp = front;
    printf("Element %d deleted from Queue.\n", front->data);
    front = front->next;
    free(temp);
	}   
}
void peek()
{
    if (front == NULL) 
        printf("Underflow condition, Queue is empty.\n");
    else
    	printf("Top element of the Queue is: %d\n", front->data);
}
void isEmpty()
{
	if(front==NULL && rear==NULL) printf("TRUE\n");
	else printf("FALSE\n");
}
void main()
{
	int choice;
	while(1)
	{
		printf("\n1.exit\n2.display\n3.Enqueue\n4.Dequeue\n5.Peek\n6.IsEmpty\n");
		printf("Enter choice:\t");scanf("%d",&choice);
		switch(choice)
		{
			case 1:exit(0);
			case 2:display();break;
			case 3: enqueue();break;
			case 4:dequeue();break;
			case 5:peek();break;
			case 6:isEmpty();break;
			default:printf("Invalid choice\n");
		}
	}
}
