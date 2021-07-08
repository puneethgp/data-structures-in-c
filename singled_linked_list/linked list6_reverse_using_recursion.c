
//reversing the list using recurrsion


#include<stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int x)
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
   else
    {
        struct Node* temp1 = head;
        while (temp1->next != NULL)
            temp1 =temp1 ->next;
        temp1->next = temp ;
    }

}

//print function using recurssion
void Print(struct Node* head)
{
    if (head==NULL)
    {
        printf("\n");return;
    }
    printf(" %d ",head->data);
    Print(head->next);

}


void Reverse(struct Node* p)
{
    if (p->next == NULL)            // p points to the last node
    {
        head = p;                   // assinging head pointer to last node
        return ;                    //exit recursion
    }

    Reverse(p->next);               // after first iteration
    struct Node *q = p->next;       // p to last second node and q points towards the last node after first recurrsion and
    q->next = p; //p->next->next=p  // revesring the direction of last node to last second node
    p->next = NULL;                 // assign null to second last pointer


}
int main()
{
    head = NULL;
    Insert(5);
    Insert(6);
    Insert(4);
    Insert(2);
    Insert(9);

    Print(head);
    Reverser(head);
    Print(head);
}


