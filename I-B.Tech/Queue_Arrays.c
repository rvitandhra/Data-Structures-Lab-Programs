//Implementation of Queue using Arrays
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int front=-1,rear=-1;
void enqueue()
{
	int value;
	printf("ENter value to insert into queue");scanf("%d",&value);
	if(front==-1 && rear==-1) 
	{
		front=rear=0;q[front]=value;
		
	}
	else if(rear==MAX-1) printf("Overflow");
	else
	{
		rear+=1;q[rear]=value;
	}
}
void dequeue()
{
	if(front==-1) printf("Underflow");
	else if(front==rear)
	{
		printf("Deleted Element in queue is %d",q[front]);front=-1;rear=-1;
	}
	else
	{
		printf("Deleted Element in queue is %d",q[front]);
		front+=1;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1) printf("Queue is Empty");
	else
	{
		printf("\nElements in Queue are:\t");
		for(i=front;i<=rear;i++) printf("%d\t",q[i]);
	}
}
void peek() {
    if (front == -1)
        printf("\nQueue is empty\n");
    else
        printf("\n Front element in Queue is %d\n", q[front]);
}
void isFull()
{
	if(rear==MAX-1) printf("\nTRUE\n");
	else printf("\nFALSE\n");
}
void isEmpty()
{
	if(front==-1) printf("\nTRUE\n");
	else printf("\nFALSE\n");
}
void main()
{
	int choice;
	while(1)
	{
		printf("\n1.exit\n2.display\n3.Enqueue\n4.Dequeue\n5.Peek\n6.IsFull\n7.IsEmpty\n");
		printf("Enter choice:\t");scanf("%d",&choice);
		switch(choice)
		{
			case 1:exit(0);
			case 2:display();break;
			case 3: enqueue();break;
			case 4:dequeue();break;
			case 5:peek();break;
			case 6:isFull();break;
			case 7:isEmpty();break;
			default:printf("Invalid choice\n");
		}
	}
}
