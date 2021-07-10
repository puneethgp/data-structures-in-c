// Implementation of Queue using arrays
/*

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int A[MAX_SIZE];
int front=-1 ,end=-1;

void Enqueue(int x)
{
    if ((front==-1 )&& (end==-1))   // if array is empty
        front+=1;

    end = (end+1)%MAX_SIZE;          // circular array implementation
                            // if array gets full but there are voids at front due Dequeue then this circular operation is helpfull;
    A[end]=x;
}

int Dequeue()
{
    if ((front==-1 )&& (end==-1)) {printf("\nThere are no elemnets in Queue\n"); return ; }      //if array is empty
    if (front==end) {int temp=end; front=-1 ; end=-1 ; return A[temp];}//only one element in the queue
    int temp = front;
    front = (front+1)%MAX_SIZE;
    return A[temp];
}

int Front()
{
    return A[front];
}
void Print()
{
    int temp = front;
    while(temp!=end+1)
    {
        if (A[temp]==0) {printf("empty queue");return;}
        printf(" %d ",A[temp++]);
    }
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    //Dequeue();Dequeue();
    Dequeue();
    Dequeue();
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);

   Print();
}
*/
