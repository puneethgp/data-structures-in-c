
//Array implementation of stacks

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20
int A[MAX_SIZE];
int top =-1;

void Push(int x)
{
    if (top == MAX_SIZE-1)
    {
        printf("\n stack is full");
        return;
    }
    A[++top]=x;
}
void Pop()
{
    if (top ==-1)
    {
        printf("\n stack is empty");
        return;

    }
    --top;
}

void Print()
{
    int temp = top ;
    while (temp >=0){
    printf(" %d  \n",A[temp]);

    temp--;
    }
    printf("\n");
}

int Top()
{
    return A[top];
}

int main(){
    Push(3);Push(4);Push(5);Push(1);Push(9);Push(2);Push(15);Push(50);
    Print();
    printf("after first pop \n");
    Pop();    Pop();

    Print();
    printf("\n");
    Push(100);Pop();Pop();
    Print();
    printf("Top is %d",Top());

}

