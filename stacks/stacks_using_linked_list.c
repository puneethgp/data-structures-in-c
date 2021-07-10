
// implementation of stacks using linked list

#include <stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(int x)                //this is same as Insert at the beginnig of linked list
{
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp ->data = x;
    temp ->next = top;
    top = temp;
}

void Pop()
{
    struct Node* temp = top;
    if (top == NULL) return;
    top = top->next;
    free(temp);
}
void Print()
{
    struct Node* temp = top ;
    while (temp >= 0)
    {
        printf(" %d \n",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    Push(3);Push(4);Push(5);
    Pop();Pop();
    Push(1);Push(9);Push(2);Push(15);Push(50);
    Print();
}


