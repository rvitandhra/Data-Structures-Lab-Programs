#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
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
        head=newNode;
    else
    {
        while(temp->next !=NULL) temp=temp->next;
        temp->next=newNode;
    }
    printf("Inserted element %d at end of LL",value);
}
void insertBegin()
{
    int value;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter elem value: ");scanf("%d",&value);
    newNode->data=value;
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
    struct node *temp=head;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(temp->next==NULL)
    {
        printf("Element : %d got deleted",head->data);
        head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL) 
        {
            temp=temp->next;
        }
        printf("Element : %d got deleted",temp->next->data);
        temp->next=NULL;
    }
}
void deleteBegin()
{
    struct node *temp=head;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head->next==NULL)
    {
        printf("Element : %d got deleted",head->data);
        head=NULL;
    }
    else
    {
        printf("Element : %d got deleted",head->data);
        head=head->next;
        temp=NULL;
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
	        temp->next=newNode;
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
	        struct node *del=temp->next;
	        temp->next=del->next;
	        printf("Element : %d got deleted at position %d",del->data,pos);
	        free(del);
	    }
    }
}
void reverseSLL_Iterative()
{
 	struct node *prev = NULL, *current = head, *temp ;
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head=prev;
    printf("Successfuly all nodes got reversed in SLL by Iteartive method");
}
void reverseSLL_Recursive(struct node *current) {
    if (current == NULL) {
        printf("Successfully reversed all nodes in SLL by Recursive method\n");
        return;
    }

    if (current->next == NULL) {
        head = current;
        printf("Successfully reversed all nodes in SLL by Recursive method\n");
        return;
    }

    reverseSLL_Recursive(current->next);
    current->next->next = current;
    current->next = NULL;
}
void removeDuplicates() 
{
    struct node *current, *index, *temp;
    current = head;
    while (current != NULL) 
	{
        temp = current;
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                index = temp->next;
                temp->next = temp->next->next;
                free(index);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
        printf("\nSuccessfully removed duplicates\n");
    }
}
void main() 
{
    int choice;
    while(1)
    {
        printf("\n 1.Exit\n2.Display\n3.InsertEnd\n4.InserBegin\n5.DeleteEnd\n6.DeleteBegin\n7.InsertAtPosition");
        printf("\n8.DeleteAtPosition\n9.reverseSLL_Ierative\n10.reverseSLL_Recursive\n11.removeDuplicates\n");
    
        printf("\nEnter Choice\n");scanf("%d",&choice);
        switch(choice)
        {
            case 1:exit(0);
            case 2: display();break;
            case 3: insertEnd();break;
            case 4:insertBegin();break;
            case 5: deleteEnd();break;
            case 6: deleteBegin();break;
            case 7:insertAtPosition();break;
            case 8:deleteAtPosition();break;
            case 9:reverseSLL_Iterative();break;
            case 10:reverseSLL_Recursive(head);break;
            case 11:removeDuplicates();break;
        }
    }
}
