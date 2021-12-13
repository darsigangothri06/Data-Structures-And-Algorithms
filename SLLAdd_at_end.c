#include<stdio.h>
#include<stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE* ADD_AT_END(NODE* START, int X)
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
    while (!(p -> LINK == NULL))
    {
        printf("%d\t", p -> DATA);
        p = p -> LINK;
    }
    printf("%d\n", p -> DATA);

    return START;
}

int main()
{
    NODE *p = ADD_AT_END(NULL,12);
    printf("After adding at end, Start address is: %u \n",p);
    NODE *q = ADD_AT_END(p,129);
    printf("After adding at end, Start address is: %u \n",q);
    NODE *r = ADD_AT_END(q,122);
    printf("After adding at end, Start address is: %u \n",r);
    NODE *s = ADD_AT_END(r,112);
    printf("After adding at end, Start address is: %u \n",s);
    return 0;
}