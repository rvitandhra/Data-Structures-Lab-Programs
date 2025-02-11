#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void display()
{
    struct node *temp=head;
    if(head==NULL) printf("No nodes in Linked List");
    else
    {
        printf("Elements in LL are: ");
        while(temp!=NULL)
        {
            printf("%d\t", temp->data);temp=temp->next;
        }
    }
}
void insertEnd()
{
    struct node *temp=head;int value;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter elem value: ");scanf("%d",&value);
    newNode->data=value;newNode->next=NULL;
    if(head==NULL)
    {
		 head=newNode;tail=newNode;
	}
    else
    {
     	newNode->prev=tail;tail->next=newNode;tail=newNode;   
    }
    printf("Inserted element %d at end of LL",value);
}
void insertBegin()
{
    int value;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter elem value: ");scanf("%d",&value);
    newNode->data=value;
    newNode->prev=NULL;
    if(head==NULL)
        head=newNode;
    else
    {
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted element %d at begin of LL",value);
}
void deleteEnd()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head==tail)
    {
        printf("Element : %d got deleted",head->data);free(head);
        head=NULL;tail=NULL;
    }
    else
    {
        printf("Element : %d got deleted",tail->data);
        struct node *temp=tail;
        tail=temp->prev;free(temp);tail->next=NULL;
        //tail=tail->prev;tail->next=NULL;
    }
}
void deleteBegin()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head==tail)
    {
        printf("Element : %d got deleted",head->data);free(head);
        head=NULL;tail=NULL;
    }
    else
    {
        printf("Element : %d got deleted",head->data);
        head=head->next;head->prev=NULL;
    }
}
void insertAtPosition()
{
    int pos,value,i;
    struct node *temp=head;
    printf("Enter position to insert node:\n");
    scanf("%d",&pos);
    
    if(pos <= 0 ) printf("Enter correct position for Insertion");
    else if(pos==1) insertBegin();
    else
    {
        for(i=1;i<pos-1;i++) {temp=temp->next;}
        if(temp->next==NULL) insertEnd();
        else
		{
			struct node *newNode = (struct node *) malloc(sizeof(struct node));
	    	printf("Enter elem value: ");scanf("%d",&value);
	    	newNode->data=value;
	        newNode->next=temp->next; 
	        temp->next=newNode; newNode->prev=temp;
	        temp=newNode->next;temp->prev=newNode;
	        printf("Inserted element %d at position %d of LL",value,pos);
	    }
    }
}
void deleteAtPosition()
{
    int pos,i;
    struct node *temp=head;
    printf("Enter position to delete node:\n");
    scanf("%d",&pos);
    if(pos <= 0 ) printf("Deletion not possible");
    else if(pos==1) deleteBegin();
    else
    {
        for(i=1;i<pos-1;i++) temp=temp->next;
        if(temp->next==NULL) deleteEnd();
        else
        {
	        //struct node *del=temp->next;
	        printf("Element : %d got deleted at position %d",temp->next->data,pos);
	        temp->next=temp->next->next;
			if(temp->next!=NULL)temp->next->prev=temp;
	        
	        //temp->next=del->next;free(del);del=temp->next;del->prev=temp;
	    }
    }
}
void reverseDisplay_DLL()
{
	if(head==NULL) printf("No nodes to reverse a Linkedlist\n");
	else
	{
		struct node *temp=tail;
		printf("\n Displaying DLL elements in Reverse order\n");
		while(temp!=head)
		{
			printf("%d\t",temp->data); temp=temp->prev;
		}
		printf("%d\t",head->data);
	}
}
void reverseDLL() 
{
    struct node *temp = NULL, *current = head;
    while (current != NULL) 
    {

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    
    if (temp != NULL) {
        tail = head; 
        head = temp->prev; 
    }
    printf("Successfully reversed all nodes in DLL by Iterative method\n");
}
void main() {
    int choice;
    while(1)
    {
        printf("\n 1.Exit\n2.Display\n3.InsertEnd\n4.InserBegin\n5.DeleteEnd\n6.DeleteBegin\n7.InsertAtPosition");
        printf("\n8.DeleteAtPosition\n9.reverseDisplay_DLL\n10.ReverseDLL\n");
    
        printf("\nEnter Choice\n");scanf("%d",&choice);
        switch(choice)
        {
            case 1: exit(0);
            case 2: display();break;
            case 3: insertEnd();break;
            case 4: insertBegin();break;
            case 5: deleteEnd();break;
            case 6: deleteBegin();break;
            case 7: insertAtPosition();break;
            case 8: deleteAtPosition();break;
            case 9: reverseDisplay_DLL();break;
            case 10: reverseDLL();break;
        }
    }
}
