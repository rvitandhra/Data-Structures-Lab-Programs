//All Stack Implementation using Arrays in C
#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int stack[MAX];
int top=-1;
void display()
{
	int i;
	printf("\nElements in Stack are:\t");
	for(i=top;i>=0;i--) printf("%d\t",stack[i]);
}
void push()
{
	int value;
	if(top==MAX-1) printf("\nStack Overflow..\n");
	else
	{
		printf("\nEnter element value to insert into Stack\n");scanf("%d",&value);
		top++;
		stack[top]=value;
	}
}
void pop()
{
	if(top==-1) printf("Underflow\n");
	else
	{	
		printf("Deleted Element in stack is %d",stack[top]);
		top--;
	}
}

void peek() {
    if (top == -1)
        printf("\nStack is empty\n");
    else
        printf("\nTop element in stack is %d\n", stack[top]);
}
void isFull()
{
	if(top==MAX-1) printf("\nTRUE\n");
	else printf("\nFALSE\n");
}
void isEmpty()
{
	if(top==-1) printf("\nTRUE\n");
	else printf("\nFALSE\n");
}
void main()
{
	int choice;
	while(1)
	{
		printf("\n1.exit\n2.display\n3.push\n4.pop\n5.peek\n6.isFull\n7.isEMpty\n");
		printf("Enter choice:\t");scanf("%d",&choice);
		switch(choice)
		{
			case 1:exit(0);
			case 2:display();break;
			case 3: push();break;
			case 4:pop();break;
			case 5:peek();break;
			case 6:isFull();break;
			case 7:isEmpty();break;
			default:printf("Invalid choice\n");
		}
	}
}
