#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE *START = NULL;

void AddAtBegin(int X)
{
    NODE *TEMP, *p;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = START;

    if(START == NULL)
    {
        START = TEMP;
        START -> LINK = START;
    }
    else
    {
        p = START;
        while(p -> LINK != START)
            p = p -> LINK;
        p -> LINK = TEMP;
        START = TEMP;
    }
}

void DISPLAY()
{
    NODE *p = START;
    printf("\nBEGIN -> ");
    while(p -> LINK != START)
    {
        printf("%d ->", p -> DATA);
        p = p -> LINK;
    }
    printf("%d -> END\n", p -> DATA);
}

void main()
{
    AddAtBegin(10);
    AddAtBegin(20);
    AddAtBegin(30);
    AddAtBegin(40);
    DISPLAY();
}