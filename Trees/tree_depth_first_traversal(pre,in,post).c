
#include<math.h>
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
    else if (x <=root->data)
        root->left = Insert(root->left,x);
    else
        root->right = Insert(root->right,x);
    return root;
}


void Preorder(struct BSTNode* root)
{
    if (root == NULL) return ;
    printf(" %d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct BSTNode* root)
{
    if (root==NULL) return ;
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
}

void Postorder(struct BSTNode* root)
{
    if (root==NULL) return ;
    Postorder(root->left);
    Postorder(root->right);
    printf(" %d ",root->data);

}


int main()
{
    struct BSTNode* root=NULL;
    root = Insert(root,10);
    root = Insert(root,5);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,3);
    root = Insert(root,11);
    root = Insert(root,15);
    printf("%d",Search(root,10));
    printf("\n min %d max = %d\n",FindMin(root),FindMax(root));
    printf("\n Preorder");
    Preorder(root);
    printf("\n Inorder");
    Inorder(root);
    printf("\n Postorder");
    Postorder(root);
}

