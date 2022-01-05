#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    struct TAG *PREV;
    int DATA;
    struct TAG *NEXT;
};

typedef struct TAG NODE;

NODE* AddAtBegin(NODE* START, int X)
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
    NODE *P = AddAtBegin(NULL,23);
    printf("Added %u\n",P);
    NODE *Q = AddAtBegin(P,213);
    printf("Added %u\n",Q);
    NODE *R = AddAtBegin(Q,223);
    printf("Added %u\n",R);
    NODE *S = AddAtBegin(R,233);
    printf("Added %u\n",S);
}