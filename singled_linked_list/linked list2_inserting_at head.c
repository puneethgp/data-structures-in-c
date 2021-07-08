//inserting at the beginnig

#include <stdio.h>
#include <stdlib.h>

//inserting node at the begining
struct Node{
    int data;
    struct Node* next;// address /link to next elment

};

// struct Node* head;//pointer to the linked list

//function protypes declared
struct Node* Insert(struct Node* head,int x);
void Print(struct Node* head);

int main()
{

struct Node* head = NULL;// empty list
    int n,i,x;
    printf(" Enter the number of elements you wish to enter \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter your number \n");
        scanf("%d",&x);
        head = Insert(head,x);// call user defined function insert to insert element at the begininng
        Print(head);//call user defined function print to display all the nodes
    }

}


struct Node* Insert(struct Node* head,int x)
{
                        //type casting to node data type
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    //adding elements
    temp->data = x;
    temp->next = NULL; // assing null if list is empty or
                       //fetches previous address stored in head
    if (head!=NULL) temp->next = head;

    // changing value of head to address of the inserted element
    head = temp;
    return head;
}

void Print(struct Node *head)
{
//    struct Node* temp = head;
    printf("elements of list are  ");
    while(head!=NULL)
    {
        printf(" %d ",head->data);
        head=head->next;
    }

}

