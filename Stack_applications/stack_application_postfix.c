//using array implementation of stack to perform postfix operation


/*logic:
* given the expression
* we push the leftmost element to stack as it is to performed last
* adding numbers to stack from  left to right of expression
* if the operator is found POP out the last the elements and evalute
*PUSH back result of each evalution back to stack
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE  100

int A[MAX_SIZE];
int top =-1;

void Push(int x)
{
    A[++top]= x;
}

int Pop()
{
    return A[top--];
}

void Print()
{
    int temp = top ;
    while (temp >=0)
    {
        printf(" %d  \n",A[temp]);
        temp--;
    }
    printf("\n");
}

int PostfixEvalutor(char *exp,int length,char delimiter)
{
    int i=0,num=0;
    for (i=0;i<strlen(exp);i++)
    {
        if (exp[i]==' ')
        {   if(num!=0)Push(num);
            num=0;
        }
        else if ((exp[i]>=48) && (exp[i]<=57))
        {
            num*=10;
            num= num+exp[i]-48;
        }
        else if (exp[i]=='+'||exp[i]=='*'||exp[i]=='-')
        {
            int temp1= Pop();
            int temp2 = Pop();
            if (exp[i]=='+') Push(temp2+temp1);
            if (exp[i]=='-') Push(temp2-temp1);
            if (exp[i]=='*') Push(temp2*temp1);
            if (exp[i]=='/') Push(temp2/temp1);
        }
    }
    return Pop();
}

int main()
{
    char exp[MAX_SIZE] = "23 54 * 9 -" ;
    char delimiter =' ';
    printf("After postfix evalu %d",PostfixEvalutor(exp,strlen(exp),delimiter));
}
