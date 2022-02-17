#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LEFT, *RIGHT;
};

typedef struct TAG NODE;

NODE *START = NULL;

void AddAtEnd(int X)  // Add at begin and Add at end are same
{
    NODE *TEMP, *p;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> LEFT = NULL;
    TEMP -> DATA = X;
    TEMP -> RIGHT = NULL;

    if(START == NULL)
    {
        START = TEMP;
        START -> LEFT = START;
        START -> RIGHT = START;
    }

    else
    {
        p = START;
        while(p -> RIGHT != START) p = p -> RIGHT;

        TEMP -> RIGHT = START;
        TEMP -> LEFT = p;
        p -> RIGHT = TEMP;
        START -> LEFT = TEMP;
    }
}

void DISPLAY()
{
    NODE *p = START;
    printf("\nBegin -> ");
    while(p -> RIGHT != START)
    {
        printf("%d -> ", p -> DATA);
        p = p -> RIGHT;
    }
    printf("%d -> ", p -> DATA);
    printf("End\n");
}

void AddAtPos(int X, int POS)
{
    NODE *TEMP, *p, *q;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> LEFT = NULL;
    TEMP -> DATA = X;
    TEMP -> RIGHT = NULL;

    if(START == NULL)
    {
        START = TEMP;
        START -> LEFT = START;
        START -> RIGHT = START;
    }
    else
    {
        q = NULL;
        p = START;
        for(int i = 1; i < POS; i++)
        {
            q = p;
            p = p -> RIGHT;
            if(p == NULL)
            {
                printf("\nInvalid Position");
                return;
            }
        }
        q -> RIGHT = TEMP;
        p -> LEFT = TEMP;
        TEMP -> RIGHT = p;
        TEMP -> LEFT = q;
    }
}

void main()
{
    AddAtEnd(2);
    AddAtEnd(10);
    AddAtEnd(20);
    AddAtEnd(30);
    AddAtEnd(300);
    DISPLAY();
    AddAtPos(24,2);
    DISPLAY();
    AddAtPos(34,3);
    DISPLAY();
    AddAtPos(40,5);
    DISPLAY();
}
