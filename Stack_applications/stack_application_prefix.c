
//implementaion of prefix arithematic to using stack which is implemented using array

/*
logic:
* given the expression
* we push the rightmost element to stack as it is to performed last
* adding numbers to stack from right to left
* if the operator is found POP out the last the elements and evalute
*PUSH back result of each evalution back to stack

difference betweeen postfix and prefix stack implemenation
* unlike post fix where first Popped element is second operand
,here in prefix first Pop element is first operand
*/

#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
int A[MAX_SIZE];
int top= -1;

void Push(int x)
{
    A[++top] = x;
}

int Pop()
{
    return A[top--];
}

int PrefixEvalutor(char *exp,int len,char delimiter)
{
        int i ,num=0,mul=1;

    for (i=strlen(exp)-1;i>=0;i--)
    {
        if (exp[i]==delimiter)    
        {
            if (num!=0)Push(num);
            num =0;mul=1;
        }
        else if((exp[i]>=48) && (exp[i]<=57))
        {
            num +=(exp[i]-48)*mul;
            mul*=10;
        }
        else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*'||exp[i]=='/')
        {
            int temp1 = Pop();
            int temp2 = Pop();
            if (exp[i]=='+')Push(temp1+temp2);
            if (exp[i]=='-')Push(temp1-temp2);
            if (exp[i]=='*')Push(temp1*temp2);
            if (exp[i]=='/')Push(temp1/temp2);
        }
    }printf("After evaluating the prefix %d ",Pop());
}
int main()
{
    char exp[]="+ * 44 11 3";
    char delimiter =' ';              // here space /empty is used as delimter , we can also use comma
    PrefixEvalutor(exp,strlen(exp),delimiter);
}

