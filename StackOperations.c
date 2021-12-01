#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
int a[SIZE], TOP = -1;
void PUSH(int);
int POP();
void DISPLAY();
int IS_FULL();
int IS_EMPTY();

int main()
{
    int X, choice, flag;
    while(1)
    {
        printf("\n---------OPERATIONS PERFORMED IN STACK----------\n1. PUSH\n2. POP\n3. DISPLAY\n4. IS_FULL\n5. IS_EMPTY\n6. EXIT\nEnter your option here: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                    {
                        printf("\nEnter element to push: ");
                        scanf("%d", &X);
                        PUSH(X);
                        DISPLAY();
                        break;
                    }
            case 2:
                    {
                        flag = POP();
                        if(flag == 0)
                        {
                            printf("\n Your stack is empty\n");
                            break;
                        }
                        else
                        {
                            printf("\nElement %d is popped out from stack", flag);
                            break;
                        }
                    }
            case 3:
                    {
                        DISPLAY();
                        break;
                    }
            case 4:
                    {
                        flag = IS_FULL();
                        if(flag == 1)
                        {
                            printf("\nYour stack is full\n");
                            break;
                        }
                        else
                        {
                            printf("\nYour stack is not full\n");
                            break;
                        }
                    }
            case 5:
                    {
                        flag = IS_EMPTY();
                        if(flag == 1)
                        {
                            printf("\nYour stack is empty\n");
                            break;
                        }
                        else
                        {
                            printf("\nYour stack is not empty\n");
                            break;
                        }   
                    }
            case 6:
            {
                exit(1);
            }
        }
    }
}

void PUSH(int X)
{
    if(TOP == (SIZE - 1)) printf("Your stack is full, Can't insert element into stack, Pop the element.\n");
    else
    {
        TOP = TOP + 1;
        a[TOP] = X;
    }
}

int POP()
{
    if(TOP == -1) return 0;
    else
    {
        int item;
        item = a[TOP];
        TOP -= 1;
        return item;
    }
}

void DISPLAY()
{
    if(TOP == -1) printf("Your stack is empty, Insert any element\n");
    else
    {
        int i;
        for(i = 0; i <= TOP; i++) printf("%5d",a[i]);
    }
}

int IS_FULL()
{
    if(TOP == (SIZE-1)) return 1;
    return 0;
}

int IS_EMPTY()
{
    if(TOP == -1) return 1;
    return 0;
}