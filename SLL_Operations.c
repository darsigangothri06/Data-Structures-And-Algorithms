#include <stdio.h>
#include <stdlib.h>
struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE* ADD_AT_POS(NODE *START, int X, int POS)
{
    NODE *TEMP, *p;
    int i;
    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = NULL;
    if(START == NULL) START = TEMP;
    else if(POS == 0)
    {
        TEMP -> LINK = START;
        START = TEMP;
    }
    else
    {
        p = START;
        for(i = 1; i < POS; i++)
        {
            p = p -> LINK;
            if(p == NULL)
            {
                printf("Invalid Position\n");
                return START;
            }
        }
        TEMP -> LINK = p -> LINK;
        p -> LINK = TEMP;
    }
    return START;
}