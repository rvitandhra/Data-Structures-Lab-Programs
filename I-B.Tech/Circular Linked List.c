#include<stdio.h>
#include<stdlib.h>
struct cnode
{
	int data;
	struct cnode *next;
};
struct cnode *head=NULL;
void display()
{
	struct cnode *temp=head;
	if(head==NULL) printf("No nodes in CLL\n");
	else{
	
		printf("Elements in CLL are:  ");
		do
		{
		  printf("%d\t",temp->data);temp=temp->next;
		} while(temp!=head);
	}
}
void insertEnd()
{
	int value;
	struct cnode *newNode=(struct cnode *) malloc(sizeof(struct cnode));
	printf("Enter element value of node:  ");
	scanf("%d",&value);
	newNode->data=value;
	if(head==NULL) {
	head=newNode; newNode->next=head;}
	else
	{
		struct cnode *temp=head;
		while(temp->next!=head) temp=temp->next;
		temp->next=newNode;newNode->next=head;
		
	}
	printf("Inserted element %d at end",newNode->data);
}

void insertBegin()
{
    int value;
    struct cnode *newNode = (struct cnode *) malloc(sizeof(struct cnode));
    printf("Enter elem value: ");scanf("%d",&value);
    newNode->data=value;
    if(head==NULL)
        {
		head=newNode;head->next=head;}
    else
    {
    	struct cnode *temp = head;
        while (temp->next != head)
            temp = temp->next;
        
        temp->next = newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted element %d at begin of LL",value);
}
void deleteEnd()
{
    struct cnode *temp=head;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head->next==head)
    {
        printf("Element : %d got deleted",head->data);free(head);
        head=NULL;
    }
    else
    {
        while(temp->next->next!=head) 
        {
            temp=temp->next;
        }
        printf("Element : %d got deleted",temp->next->data);
        free(temp->next);
        temp->next=head;
    }
}
void deleteBegin()
{
    struct cnode *temp=head;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(head->next==head)
    {
        printf("Element : %d got deleted",head->data);free(head);
        head=NULL;
    }
    else
    {
    	struct cnode *temp = head;
        while (temp->next != head)
            temp = temp->next;
        printf("Element : %d got deleted",head->data);
        head=head->next;
        temp->next=head;
        
    }
}
void insertAtPosition()
{
    int pos,value,i;
    struct cnode *temp=head;
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
	        struct cnode *newNode = (struct cnode *) malloc(sizeof(struct cnode));
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
    struct cnode *temp=head;
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
	        struct cnode *del=temp->next;
	        temp->next=del->next;
	        printf("Element : %d got deleted at position %d",del->data,pos);
	        free(del);
	    }
    }
}
void reverseCLL() 
{
    if (head == NULL) {
        printf("Empty list!\n");
    }

    struct cnode *prev = NULL, *current = head, *nextNode;
    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head->next = prev;
    head = prev;
    printf("Successfully reversed all nodes in CLL by Iterative method\n");
}
void main() 
{
    int choice;
    while(1)
    {
        printf("\n 1.Exit\n2.Display\n3.InsertEnd\n4.InserBegin\n5.DeleteEnd\n6.DeleteBegin");
        printf("\n7.InsertAtPosition\n8.DeleteAtPosition\n9.reverseCLL");
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
            case 9:reverseCLL();break;
            
        }
    }
}


