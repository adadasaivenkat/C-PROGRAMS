#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


int *stack=NULL;
int top=-1;


void push(int N)
{
    if (top==(N-1))
    {
        printf("Stack is full!Cannot push!!\n");
    }
    else
    {
        int x;
        printf("Enter data : ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        printf("%d pushed onto the stack\n",x);
    }
}


void pop()
{
    if (top==-1)
    {
        printf("Stack is empty!Cannot pop!!\n");
    }
    else
    {
        int item;
        item=stack[top];
        top--;
        printf("%d popped from the stack\n",item);
    }
}


void peek()
{
    if(top==-1)
    {
        printf("Stack is empty!Cannot peek!!\n");
    }
    else
    {
        printf("Top element : %d\n",stack[top]);
    }
}


void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int i;
        printf("Stack size : %d\n",top+1);
        printf("Stack elements : ");
        for(i=top; i>=0; i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}


int main()
{
    int N;
    printf("Enter the stack size : ");
    scanf("%d",&N);
    stack=(int *)malloc(N*sizeof(int));
    if(stack==NULL)
    {
        printf("Memory allocation failed!Exiting!!\n");
        exit(1);
    }
    int choice;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    push(N);
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                    peek();
                    break;
            case 4: 
                    display();
                    break;
            case 5:
                    display();
                    free(stack);
                    exit(0);
                    break;
            default:
                    printf("Entered an invalid choice!!\n");
        }
    }
    return 0;
}