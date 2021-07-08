

// Implementation of linked list :inserting at nth postion

#include<stdio.h>
#include<conio.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head ;

void Insert(int data,int n)         // n is according 1 based system ie indexing starts from 1,2,3 and ....
{
    struct Node* temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->next=NULL;
    temp1->data = data;
    if (n ==1)
    {
        temp1->next = head;
        head = temp1;
        return;

    }
    struct Node* temp2 = head;
    int count=0;
    while (count<n-2)           // selection of prevoius to n_th node and as n is 1 based we should do n-2
    {
        count+=1;
        temp2 = temp2->next ;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;

}
void Print()
{
    struct Node* temp = head;
    while (temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp = temp ->next;

    }

}
int main()
{
    head = NULL;//empty list
    Insert(4,1); //4
    Insert(5,2); //4->5
    Insert(3,1); //3->4->5
    Print();
}
