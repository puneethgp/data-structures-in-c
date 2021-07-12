
//trees implementation without recurssion

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root;

struct Node* GetNewNode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Insert(int x)
{
    struct Node* temp=root;
    if (root == NULL) root = GetNewNode(x);
    while(temp!=NULL)
    {
    if (x<temp->data)
        {
            if (temp->left == NULL) {temp->left = GetNewNode(x);return;}
            temp = temp->left;}
    else
        {
            if (temp->right == NULL) {temp->right = GetNewNode(x);return;}
            temp= temp->right;
        }
    }
}

_Bool Search(int x)
{
    if (root==NULL) return false;
    struct Node* temp =root;
    while (temp->left!=NULL||temp->right!=NULL)
    {
        if (x>temp->data) temp=temp->right;
        if (x<temp->data) temp = temp->left;
        if (x==temp->data) return true;
    }
    return false;
}

int FindMin()
{
if (root==NULL)
    {
        printf("root is empty\n");
        return;
    }
    struct Node* temp = root;
    while (temp->left!=NULL) temp = temp->left;
    return temp->data;
}
int FindMax()
{
if (root==NULL)
    {
        printf("root is empty\n");
        return;
    }
    struct Node* temp = root;
    while (temp->right!=NULL) temp = temp->right;
    return temp->data;
}
int main()
{
    root = NULL;
    Insert(5);Insert(7);Insert(4);Insert(9);Insert(10);Insert(11);Insert(4);Insert(15);Insert(20);;
    printf("%d",(Search(5)?true:false));
    printf("\n min %d max = %d\n",FindMin(),FindMax());
}


