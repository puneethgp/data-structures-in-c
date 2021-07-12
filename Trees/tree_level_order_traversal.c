
//level order traversal of binary tree using queues

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

//queue

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front ;
struct Node* rear ;

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
    else if (front==rear) front = rear = NULL;    //after deletion of last element
    else front = front->next;
    free(temp);
}

int Front()
{
    if (front==NULL) printf("NO elements") ;
    else return front->data;
}

_Bool Empty()
{
    if (front==NULL && rear == NULL)
        return true;
    else false;
}

//tree implementation

struct BSTNode
{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode* GetNewNode(int x)
{
    struct BSTNode* temp = (struct Node*)malloc(sizeof(struct BSTNode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct BSTNode* Insert(struct BSTNode* root,int x)
{
    if (root == NULL)
        root = GetNewNode(x);
    else if (x <=root->data)
        root->left = Insert(root->left,x);
    else
        root->right = Insert(root->right,x);
    return root;
}

//level order traversal of trees
 /*
 logic
first we push parent node to stack and then child node to stacks
after completion of all childnodes of one particular level we pop out parent node

*/

void LevelOrderTraversal(struct BSTNode* root)
{
    if (root == NULL) return ;
    Enqueue(root);
    while(!Empty())
    {
        struct BSTNode* temp = Front();
        printf(" data %d",temp->data);
        // here we are not moving to left or right subtree
        //but instead we push child elements to queue and then pop the parnet node
        if (temp->left!=NULL) Enqueue(temp->left);
        if (temp->right!=NULL) Enqueue(temp->right);
        Dequeue();  //poping out the front element
    }
}
void main()
{
    front = NULL;
    struct BSTNode* root=NULL;
    root = Insert(root,10);
    root = Insert(root,5);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,3);
    root = Insert(root,11);
    root = Insert(root,15);
    LevelOrderTraversal(root);

}


