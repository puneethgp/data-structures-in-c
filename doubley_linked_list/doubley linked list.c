
// doubley linked list implementation


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;          // creating pointer to store previous address
    struct Node* next;             // creating pointer to store previous address
};

struct Node* head;

void Insert_at_beginning(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = x;
    if (head == NULL)
    {
        head = temp;
        temp->next =NULL;
        return;
    }
    head ->prev = temp;
    temp ->next = head;
    head = temp;

}


void Insert_at_end(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = head;
        head = temp;
    }
    else
    {
        struct Node* temp1 = head;
        while(temp1->next !=NULL)
            temp1 = temp1->next ;
        temp->prev = temp1;
        temp1->next = temp;

    }
}

void Print()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data );
        temp = temp->next;
    }
}

void Reverse()
{
    struct Node* temp = head ;
    if (temp ==NULL) return;
    while (temp->next!=NULL)
        temp=temp->next;

    while (temp!= NULL)
    {
     printf(" %d ",temp->data);
        temp =temp->prev;
    }
printf("\n");
}
int main()
{
    head = NULL;

    Insert_at_beginning(4);
    Insert_at_beginning(6);
    Insert_at_beginning(8);
    Insert_at_end(10);
    Insert_at_beginning(2);
    Insert_at_end(1); 
    Insert_at_end(10);
    Insert_at_end(10);
    printf("Before reversal\n");
    Print();
    printf("\n");
    printf("After reversal \n");
    Reverse();

}
