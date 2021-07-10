
// implementation of Queue using linkedlist

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front ;
struct Node* rear ;       // we use pointer the rear part of queue so that deletion can be
                                // be done at the time complexity of O(1)
// if there was no pointer to rear end we should have traversed the whole linked list at find the
//end node ,which leads to O(n)

/*
    visulation of queue 
    
     front =>100                                               rear=>300

    _100_______    _900_______    __500_____    __300______   _300________
    | 1 | 900 | => | 2 | 500 | => | 3 | 300| => | 4 | 200 | =>| 5 |  Null|

*/

void Enqueue(int x)             // using insertion at rear and deletion at front
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if ((front==NULL) && (rear == NULL))
        front = temp;
    else
        rear->next = temp;
    rear = temp;       // changing the rear pointer as we are inserting at end
}

void Dequeue()
{
    struct Node *temp = front;
    if (front==NULL) return;        //for null queues
    else if (front==rear) front = rear= NULL;    //after deletion of last element
    else front = front->next;
    free(temp);
}

int Front()
{
    if (front==NULL) printf("NO elements") ;
    else return front->data;
}

void Empty()
{
    if (front==NULL && rear == NULL)
        printf("\nqueue is empyt\n");
    else printf("\n queue is not empty");
}

void Print()
{
    struct Node* temp = front;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    front = NULL;
    Enqueue(2);
    Enqueue(5);
    Enqueue(6);
    //Enqueue(7);
    Enqueue(8);
    Print();
    Dequeue();
    printf("\n");
    Print();
    Empty();
    printf("\n Front member in queue %d\n",Front());
    Dequeue();
    Dequeue();
    //Dequeue();
    Dequeue();
    Empty();
}
