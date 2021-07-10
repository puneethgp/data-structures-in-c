
#include <stdio.h>
#include<conio.h>

#define MAX_SIZE 100

int top = -1;
char A[MAX_SIZE];

void Push(char x)
{
    A[++top]=x;
}

void Pop()
{
    top--;
    //return A[top--];          // use this for implementation without Top()
}
char Top()
{
    return A[top];
}

void Reverse(char *string,int n)
{
    int i;
    for (i=0;i<n;i++)
        Push(string[i]);
    for (i=0;i<n;i++)
    {                    // This can be done without implementing Top function
        string[i]=Top(); // this can also be done by returning char directly from Pop func
                         // and replace it with original array
         Pop();
    }
}
int main()
{
    char string[15] = "HELLO World";
    Reverse(string,strlen(string));
    int i;
    for (i=0;i<strlen(string);i++)
    {
        printf("%c",string[i]);
    }
}

/*alternative approach for increasing efficency

time complexity and space complexity is O(n)
 we can reduce space complexity to O(1) by
 having 2 pointers one at head(i) and 1 at tail(j)
if i >j we swap values else nothing
*/
