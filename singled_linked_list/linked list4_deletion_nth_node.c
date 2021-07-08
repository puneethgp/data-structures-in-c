
//deletion of element at n_th node 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * head;

void Insert(int x , int pos)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = x;
    int i ;
    struct Node* temp2 = head;
    if (pos == 1)
    {
        temp1->next = head;
        head = temp1;return;

    }
    for(i=0;i<pos-2;i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;

}

void Print()
{
    struct Node* temp = head;
    while(temp!= NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->next;
    }
}

void Delete(int pos)
{
    struct Node* temp = head;
    int i ;
    for (i=0;i<pos-2;i++)
        temp = temp->next;
    temp->next = (temp->next)->next;

}

void main()
{
    head = NULL;
    Insert(1,1);
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,1);
    Insert(7,1);
    Print();
    printf("\n");
    Delete(4);          //position of the element in 1 based number system
    Print();
}



