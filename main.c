/**

This is a program developed by Priyankar Koley.
It's a menu-driven program. In this program user can
1. Create a Linked List
2. Insert a NODE at the beginning
3. Insert a NODE at the end
4. Insert a NODE after any element
5. Delete a NODE at the beginning
6. Delete a NODE at the end
7. Delete any NODE
8. View the list
9. Sort the list
10. Reverse the list
11. Search in the list
OR, 12. EXIT

**/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int x;
    struct list* next;
} l;

char ch;
l* head;

void create(l*);
void insertAtBeginning(l*);
void insertAtEnd(l*);
void insertAfterAnyPos(l*);
void deleteAtBeginning(l*);
void deleteAtEnd(l*);
void deleteAtAnyPos(l*);
void view(l*);
void sort(l*);
l* rev(l*);
void search(l*);



void create(l* ptr)
{
    printf("Enter the value: ");
    scanf("%d", &ptr->x);
    ptr->next=NULL;
    printf("Do you want to continue?");
    scanf(" %c", &ch);
   /** while(ch=='y'||ch=='Y')
    {
        ptr->next=(l*)malloc(sizeof(l));
        ptr=ptr->next;
        create(ptr);
    }**/
}

void view(l* ptr)
{
    while(ptr!=NULL)
    {
        printf("\n%d", ptr->x);
        ptr=ptr->next;
    }
}

void insertAtBeginning(l* ptr)
{
    l* new = (l*)malloc(sizeof(l));
    printf("Enter the value: ");
    scanf("%d", &new->x);
    new->next = head;
    head = new;
}

void insertAtEnd(l* ptr)
{
    l* new = (l*)malloc(sizeof(l));
    printf("Enter the value: ");
    scanf("%d", &new->x);
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

void insertAfterAnyPos(l* ptr)
{
    while(ptr->next!=NULL)
    {
        if(ptr->x == NULL)
        {
            l* new = (l*)malloc(sizeof(l));
            printf("Enter the value: ");
            scanf("%d", &new->x);
            new->next = ptr->next;
        }
        ptr = ptr->next;
    }
}

void deleteAtBeginning(l* ptr)
{
    l* node = ptr;
    head = ptr->next;
    free(node);
}

void deleteAtEnd(l* ptr)
{
    l* ptr1;
    while(ptr1->next!=NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr->next;
    }
    ptr->next=NULL;
    free(ptr1);
}

void deleteAtAnyPos(l* ptr)
{
    int ele;
    l* ptr1 = ptr->next;
    printf("Enter the value to be deleted: ");
    scanf("%d", &ele);
    while(ptr1!=NULL)
    {
        if(ptr1->x == ele)
        {
            ptr->next = ptr1->next;
            free(ptr1);
        }
    }
}

void sort(l* ptr)
{
    l* ptr1;
    for(;ptr->next!=NULL;ptr = ptr->next)
    {
        for(ptr1=ptr->next;ptr1->next!=NULL;ptr1 = ptr1->next)
        {
            if(ptr->x > ptr1->x)
            {
                int temp = ptr->x;
                ptr->x = ptr1->x;
                ptr1->x = temp;
            }
        }
    }
}

l* rev(l* ptr)
{
    l* counter;
    l* current = ptr;
    l* prev = NULL;
    while(current!=NULL)
    {
        counter = current->next;
        current->next = prev;

        prev = current;
        current = counter;
    }
    ptr = prev;
    return(ptr);
}

void search(l* ptr)
{
    int ele;
    printf("Enter the value to be searched: ");
    scanf("%d", &ele);
    while(ptr!=NULL)
    {
        if(ptr->x == ele)
        {
            printf("Element found.");
        }
        ptr = ptr->next;
    }
}



void main()
{
	int choice;
	head =(l*)malloc(sizeof(l));
	while(1)
    {
        printf("\n\n\n\n1. Create a Linked List\n2. Insert a NODE at the beginning\n3. Insert a NODE at the end\n4. Insert a NODE after any element\n5. Delete a NODE at the beginning\n6. Delete a NODE at the end\n7. Delete any NODE\n8. View the list\n9. Sort the list\n10. Reverse the list\n11. Search in the list\n12. Exit");
		printf("\n\nEnter Choice :");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			create(head);
			break;
		case 2:
			insertAtBeginning(head);
			break;
		case 3:
			insertAtEnd(head);
			break;
		case 4:
			insertAfterAnyPos(head);
			break;
        case 5:
            deleteAtBeginning(head);
            break;
		case 6:
			deleteAtEnd(head);
			break;
		case 7:
            deleteAtAnyPos(head);
            break;
        case 8:
            view(head);
            break;
        case 9:
            sort(head);
            break;
        case 10:
            head = rev(head);
            break;
        case 11:
            search(head);
        case 12:
            exit(0);
            break;
		default:
			printf("Incorrect Choice\n");
		}
	}
}
