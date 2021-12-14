#include <stdio.h>
#include <stdlib.h>
struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE* DelAtEnd(NODE *START)
{
    NODE *p, *TEMP;
    if(START == NULL)
    {
        printf("Single linked list is empty, cannot delete");
        return START;
    }
    else
    {
        p = START;
        TEMP = NULL;
        while(p -> LINK != NULL)
        {
            TEMP = p;
            p = p -> LINK;
        }
        TEMP -> LINK = NULL;
        printf("Deleted: ",p -> DATA);
        free(p);
    }

    // DISPLAYING THE LINKED LIST
    p = START;
    printf("Begin ->");
    while (p != NULL)
    {
        printf(" %d -> ", p -> DATA);
        p = p -> LINK;
    }
    printf("END\n");

    return START;
}



NODE* Add_AT_POS(NODE *START, int X, int POS)
{
    NODE *TEMP, *p;
    int i;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = NULL;
    if(START == NULL) START = TEMP;  // If start is empty
    else if(POS == 0)  // Add node at begin
    {
        TEMP -> LINK = START;
        START = TEMP;
    }
    else  // Add node at certain position
    {
        p = START;
        for(i = 1; i < POS; i++)  // moving p to position.
        {
            p = p -> LINK;
            if(p == NULL) // if position is greater than no:of nodes, then when moving pointer p, we get NULL. We get last node.
            {
                printf("Invalid Position, Position is greater than Number of nodes of Linked List to insert.\n");
                return START;
            }
        }
        TEMP -> LINK = p -> LINK;
        p -> LINK = TEMP;
    }

    // DISPLAYING THE LINKED LIST
    p = START;
    printf("Begin ->");
    while (p != NULL)
    {
        printf(" %d -> ", p -> DATA);
        p = p -> LINK;
    }
    printf("END\n");

    return START;
}

int main()
{
    NODE *p = Add_AT_POS(NULL,12,0);
    printf("Start address is: %u \n",p);
    NODE *q = Add_AT_POS(p,120,1);
    printf("Start address is: %u \n",q);
    NODE *r = Add_AT_POS(q,121,0);
    printf("Start address is: %u \n",r);
    NODE *h = DelAtEnd(r);
    printf("Start address is: %u \n",h);
    NODE *i = DelAtEnd(h);
    printf("Start address isi: %u \n",i);
    
    return 0;
}