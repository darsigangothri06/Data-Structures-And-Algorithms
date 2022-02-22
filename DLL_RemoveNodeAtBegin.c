#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    struct TAG *PREV;
    int DATA;
    struct TAG *NEXT;
};

typedef struct TAG NODE;

NODE* RemoveAtBegin(NODE *START)
{
    NODE *p, *q;
    if(START == NULL)
    {
        printf("Double Linked List is empty\n");
        return START;
    }

    else
    {
        q = START;
        START = START -> NEXT;
        START -> PREV = NULL;
        q -> NEXT = NULL;
        free(q);
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

    NODE *A = RemoveAtBegin(S);
    printf("Removed %u\n",A);
    NODE *I = RemoveAtBegin(A);
    printf("Removed %u\n",I);
}