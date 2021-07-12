
//trees implementation using recurssion

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<conio.h>

//define max function
#define max(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
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

int FindMin(struct BSTNode* root)
{
    if (root==NULL)
    {
        printf("root is empty\n");
        return;
    }
    else if (root->left==NULL) return root->data;
    return FindMin(root->left);
}
int FindMax(struct BSTNode* root)
{   if (root==NULL)
    {
        printf("root is empty\n");
        return;
    }
    else if (root->right==NULL) return root->data;
    return FindMax(root->right);
}
_Bool Search(struct BSTNode* root, int x)
{
    if (root==NULL) return false;
    else if (root->data==x) return true;
    else if (x>root->data) return Search(root->right,x);
    else return   Search(root->left,x);
}

int Height(struct BSTNode* root)
{
    if (root==NULL)
        return -1;
    return max(Height(root->left),Height(root->right))+1;
}

int main()
{
    struct BSTNode* root=NULL;
    root = Insert(root,10);
    root = Insert(root,1);
    root = Insert(root,6);
    root = Insert(root,12);
    root = Insert(root,60);
    printf("%d",Search(root,10));
    printf("\n min %d max = %d\n",FindMin(root),FindMax(root));
}


