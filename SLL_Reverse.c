#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE* ADD(NODE* START, int X)
{
    NODE *TEMP, *p;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = NULL;

    if(START == NULL) START = TEMP;
    else
    {
        p = START;
        while(p -> LINK != NULL) p = p -> LINK;
        p -> LINK = TEMP;
    }

    p = START;
    printf("Begin ->");
    while(p != NULL)
    {
        printf("%d ->", p -> DATA);
        p = p -> LINK;
    } 
    printf("END\n");

    return START;
}

NODE* REV(NODE *START)
{
    NODE *prev = NULL;
    NODE *next = NULL;
    NODE *curr = START;
    NODE *p;

    while(curr != NULL)
    {
        next = curr -> LINK;
        curr -> LINK = prev;
        prev = curr;
        curr = next;
    }
    START = prev;

    p = START;
    printf("Begin ->");
    while(p != NULL)
    {
        printf("%d ->", p -> DATA);
        p = p -> LINK;
    }
    printf("END\n");

    return START;
}

int main()
{
    NODE *q = ADD(NULL,12);
    printf("%u\n",q);
    NODE *w = ADD(q,13);
    printf("%u\n",w);
    NODE *e = ADD(w,14);
    printf("%u\n",e);
    NODE *r = ADD(e,15);
    printf("%u\n",r);
    NODE *t = ADD(r,16);
    printf("%u\n",t);

    NODE *o = REV(t);
    printf("%u\n",o);

    NODE *z = ADD(o,16);
    printf("%u\n",z);
}