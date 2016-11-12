//1.h
#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
typedef struct astack *Stack;
typedef struct astack
{
 int top;
 int maxtop;
 char* data;
}Astack;
Stack NewEmpty(int size)
{
 Stack S=(Stack)malloc(sizeof(Astack));
 S->maxtop=size;
 S->top=-1;
 S->data=(char*)malloc(size*sizeof(char));
 return S;
}

int StackEmpty(Stack S)
{
 return S->top<0;
}
int StackFull(Stack S)
{
 return S->top==S->maxtop;
}
int Peek(Stack S)
{
 return S->data[S->top];
}
void Push(char x,Stack S)
{
 if(StackFull(S))
 {
  printf("Stack is full!\n");
  exit(1);
 }
    else
  S->data[++S->top]=x;
}
int Pop(Stack S)
{
 if(StackEmpty(S))
 {
  printf("Stack is empty!\n");
     exit(1);
 }
 else 
     return S->data[S->top--];
}
Stack NewStack(int size)
{
 Stack S=NewEmpty(size);
 int i,x,num;
 printf("Please enter the number of data:\n");
 scanf("%d",&num);
 for(i=0;i<num;i++)
 {
  printf("Please enter the %d date:\n",i+1);
  scanf("%c",&x);
  Push(x,S);
 }
 return S;
} 
void ShowStack(Stack S)
{
 int i;
 for(i=0;i<=S->top;i++)
 {
  printf(" %c",S->data[i]);
 }
 printf("\n");
}
#endif









//1.c
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//#include"1.h"
#define MAX 30

int Precedence(char ch)
{
 if(ch=='+'||ch=='-')return 2;
 else if(ch=='*'||ch=='/')return 3;
 else if(ch=='('||ch==')')return 4;
 else if(ch=='@')return 1;
 else return 0;
}

void Change(char *s1,char *s2)
{
 Stack S=NewEmpty(MAX);
 int i=0,j=0,one=0;
 char ch=s1[i];
 Push('@',S);
 while(ch!='@')
 {
  if(ch==' ')
   ch=s1[++i];
  else if(isalnum(ch)!=0)
  {
   if(one==1)
   {
    s2[j++]=' ';
   }
    s2[j++]=ch;
    ch=s1[++i];
    one=0;
  }
  else if(ch=='(')
  {
   Push(ch,S);
   ch=s1[++i];
   one=1;
  }
  else if(ch==')')
  {
   while(Peek(S)!='(')
    s2[j++]=Pop(S);
   Pop(S);
   ch=s1[++i];
   one=1;
  }
  else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
  {
   while(Peek(S)!='('&&Precedence(Peek(S))>=Precedence(ch))
   {
    s2[j++]=Pop(S);
    one=1;
   }
   Push(ch,S);
   ch=s1[++i];
   one=1;
  }
 }
 while(StackEmpty(S)!=1)
 {
  s2[j++]=Pop(S);
  one=1;
 }

 s2[j]='\0';
}
int main()
{
 char s1[MAX],s2[MAX];
 printf("Enter the equation:\n");
 gets(s1);
 Change(s1,s2);
 printf("%s\n",s2);
 return 0;
}

