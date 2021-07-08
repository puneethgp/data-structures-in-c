// reversing the linked list by altering the links of the node(here Next) 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int x);
void Reverse();
void Print();

int main()
{
    head = NULL;
    Insert(4);
    Insert(6);
    Insert(1);
    Insert(8);
    Print();
    Reverse();
    printf("\n after reversing \n");
    Print();
}

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = NULL;
    if (head==NULL ) head = temp;
    else
    {
        struct Node* temp1 = head;
        while (temp1->next != NULL) temp1= temp1->next;
        temp1->next = temp;
    }
}

void Print()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf(" %d " ,temp->data);
        temp = temp ->next;
    }

}

void Reverse()
{
    struct Node* prev,*next,*current;
    prev = NULL;
    current = head;
    while(current!=NULL)
    {
        next = current -> next;
        current->next = prev;
        prev = current;
        current = next;


    }
    head = prev;

}
