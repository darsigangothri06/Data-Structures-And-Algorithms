#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    struct TAG *PREV;
    int DATA;
    struct TAG *NEXT;
};

typedef struct TAG NODE;

NODE* AddAtPos(NODE* START, int X, int POS)
{
    NODE *temp, *p, *q;
    int i;
    temp = (NODE*)malloc(sizeof(NODE));
    temp -> PREV = NULL;
    temp -> DATA = X;
    temp -> NEXT = NULL;

    if(START == NULL)
        START = temp;
    else if(POS == 0)
    {
        temp -> NEXT = START;
        START = temp;
    }
    else
    {
        p = START;
        q = NULL;
        for(i = 0; i < (POS - 1); i++)
        {
            if(p == NULL)
            {
                printf("\nCannot Add due to insufficient nodes\n");
                return START;
            }
            q = p;
            p = p -> NEXT;
        }
        temp -> NEXT = p -> NEXT;
        p -> NEXT = temp;
    }

    p = START;
    printf("\nBegin -> ");
    while(p != NULL)
    {
        printf("%d -> ", p -> DATA);
        p = p -> NEXT;
    }
    printf(" End\n");
    return START;
}

int main()
{
    NODE *P = AddAtPos(NULL,23,0);
    printf("Added %u\n",P);
    NODE *Q = AddAtPos(P,213,7);
    printf("Added %u\n",Q);
    NODE *R = AddAtPos(Q,89,1);
    printf("Added %u\n",R);
    NODE *S = AddAtPos(R,233,0);
    printf("Added %u\n",S);
}