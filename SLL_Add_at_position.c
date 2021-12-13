#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE* Add_AT_POS(NODE *START, int X, int POS)
{
    int i;
    NODE *p, *TEMP;
    TEMP = (NODE *)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = NULL;

    if(START == NULL) START = TEMP;
    else
    {
        p = START;
        for(i = 1; i <= POS; i++) p = p -> LINK;
        TEMP -> LINK = p -> LINK;
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
    NODE *p = Add_AT_POS(NULL,12,0);
    printf("Start address is: %u \n",p);
    return 0;
}