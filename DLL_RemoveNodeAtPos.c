#include <stdio.h>
#include <stdlib.h>

// segmentation fault

struct TAG
{
    struct TAG *PREV;
    int DATA;
    struct TAG *NEXT;
};

typedef struct TAG NODE;

NODE* RemoveNodeAtPos(NODE* START, int POS)
{
    NODE *p, *q;
    int i;
    if(START == NULL)
        printf("DLL is empty\n");
    else
    {
        for(i = 0; i < (POS - 1); i++)
        {
            q = p;
            p = p -> NEXT;
        }

        q -> NEXT = p -> NEXT;
        free(p);
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

NODE* AddAtEnd(NODE* START, int X)
{
    NODE *temp, *p;
    temp = (NODE*)malloc(sizeof(NODE));  // taking temporary node
    temp -> PREV = NULL;
    temp -> DATA = X;
    temp -> NEXT = NULL;

    if(START == NULL)  // if there is no DLL
        START = temp;
    else
    {
        p = START;
        while(p -> NEXT != NULL)    
            p = p -> NEXT; // moving p to next node
        p -> NEXT = temp; // adding temp at end
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
    NODE *P = AddAtEnd(NULL,23);
    printf("Added %u\n",P);
    NODE *Q = AddAtEnd(P,213);
    printf("Added %u\n",Q);
    NODE *R = AddAtEnd(Q,223);
    printf("Added %u\n",R);
    NODE *S = AddAtEnd(R,233);
    printf("Added %u\n",S);

    NODE *A = RemoveNodeAtPos(S,2);
    printf("Removed %u\n",A);
    NODE *I = RemoveNodeAtPos(A,2);
    printf("Removed %u\n",I);
}