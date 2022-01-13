#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;
NODE *TOP, *START = NULL;

void PUSH(int X)
{
    NODE *temp, *p;
    temp = (NODE*)malloc(sizeof(NODE));
    temp -> DATA = X;
    temp -> LINK = NULL;

    if(START == NULL)
    {
        START = temp;
        TOP = temp;
    }
    else
    {
        TOP -> LINK = temp;
        TOP = TOP -> LINK;
    }

    p = START;
    printf("\nBegin -> ");
    while(p != TOP)
    {
        printf("%d -> ", p -> DATA);
        p = p -> LINK;
    }
    printf("%d -> ", p -> DATA);
    printf("END");
}

int POP()
{
    if(START == NULL)
    {
        printf("SLL is empty");
        return -99;
    }
    else
    {
        NODE *q = START;
        int data;
        while(q -> LINK != TOP)
        {
            q = q -> LINK;
        }
        q -> LINK = NULL;
        data = TOP -> DATA;
        free(TOP);
        TOP = q;
        return data;
    }
}

int main()
{
    PUSH(12);
    PUSH(120);
    PUSH(1000);
    printf("%d", POP());
    PUSH(23);
    return 0;
}