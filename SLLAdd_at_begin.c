// Add a node at begin -- Single Linked List
#include <stdio.h>
#include <stdlib.h>
struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE* ADD_AT_BEGIN(NODE *START, int X)
{
    NODE *TEMP,*p;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = NULL;
    if(START == NULL) START = TEMP;
    else
    {
        TEMP -> LINK = START;
        START = TEMP;
    }

    printf("\nDATA in Current Linked List is: \n");
    p = START;
    while (!(p -> LINK == NULL))
    {
        printf("%d \t", p->DATA);
        p = p->LINK;
    }    
    printf("%d \n", p->DATA);  

    return START;
}

int main()
{
    NODE *p = ADD_AT_BEGIN(NULL,12);
    printf("After adding at begin, Start address is: %u \n",p);
    printf("After adding at begin, Start address is: %u \n",ADD_AT_BEGIN(p,120));
    return 0;
}