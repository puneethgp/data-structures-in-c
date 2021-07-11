#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<conio.h>

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
    else if (x >=root->data)
        root->left = Insert(root->left,x);
    else if (x < root->data)
        root->right = Insert(root->right,x);
    return root;
}


int main()
{
    struct BSTNode* root=NULL;
    root = Insert(root,10);
    root = Insert(root,5);
    root = Insert(root,15);
    printf("%d",Search(root,10));
}

