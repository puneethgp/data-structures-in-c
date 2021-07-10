

#include <stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;           // inserting elements at end
void Insert(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head== NULL) head = temp;
    else
    {
        struct Node *temp1=head;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next = temp;
    }
}

void Print()
{
    struct Node *temp =head ;
    while(temp!=NULL)
    {
        printf(" %d  \n",temp->data);
        temp= temp->next;
    }

}

//struct Node* top  ;
#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    A[++top]=x;
}

void Pop()
{
    if (top<0) return ;
    --top;
}
int Top()
{
    return A[top];
}

void Reverse()
{
    if (head == NULL ) return ;
    struct Node* temp = head;
    while(temp!=NULL)
    {
        Push(temp);
        temp =temp->next;
    }

    temp = Top();
    head = temp;
    Pop();
    while (Top()!=NULL)
    {
        temp->next = Top();
        temp = temp->next;
        Pop();
    }
    temp ->next = NULL;



}
int main()
{

    Insert(3);    Insert(4);Insert(2);Insert(1);Insert(3);Insert(5);
Print();
Reverse();
printf("\nAfter reversal\n");
Print();

}

