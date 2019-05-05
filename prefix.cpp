#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
char st[20];
char pre[20];
int t=-1;
int top=-1;
void push(char x)
{
    st[++top]=x;
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
        return st[top--];
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
}

int main()
{
    char exp[20];
    char *e,x;
    cout<<"\nEnter the expressions: ";
    cin>>exp;
    e = strrev(exp);
    for(int i=0;i<strlen(e);i++)
    {
        if(e[i]=='(')
        {
            e[i] =')';
        }
        else if(e[i]==')')
            e[i] = '(';
    }
    while(*e!='\0')
    {
        if(isalnum(*e))
            pre[++t] = *e; 
        else if(*e=='(')
            push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
                pre[++t] = x;
        }
        else
        {
            while(priority(st[top])>priority(*e))// if output is not right use '>=' instead of '>'
                pre[++t] = pop();
                push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        pre[++t]=pop();
    }
    for(int i=t;i>=0;i--)
    {
        cout<<pre[i];
    }
    getch();
    return 0;
}

