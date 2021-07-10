// compiler parenthese detection

/*
logic:
* consider  a stack
* add /push opening parenthese to the stack
* if a closing parenthese found and top of the stack is of same type
    -> then pop/ remove the top element from stack
* if stack is null after completetion then parenthese are closed correctly


*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Node* top;

void Push(char x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top ;
    top = temp;
}

void Pop()
{
    struct Node* temp = top;
    if (top ==NULL) return;
    top = top->next;
    free(temp);
}

char Top()
{
    return top->data;
}

int ProperParentheses()
{
    char s[] = "{[Puneeth] (G P) }";
    int i =0;
    for(i=0;i<strlen(s);i++)
    {
         if ((s[i]=='{') || (s[i]=='(' ) || ( s[i]=='[')) Push(s[i]);
         else if ((s[i]=='}') || (s[i]==')' ) || ( s[i]==']'))
        {
            if (Top()==s[i]) Pop();
            else return 0;
        }
    }
    printf(" %c ",Top());
    return Top()==NULL?1:0;
}

int main()
{
    printf("%d",ProperParentheses());
}


