#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int coef;
    int expo;
    struct TAG *LINK;
};

typedef struct TAG POLY;

POLY *P = NULL;

POLY* CREATE(int n)
{
    int i, c, e;
    POLY* TERM, *p;
    for(i = 1; i <= n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%d", &c);
        printf("Enter exponent: ");
        scanf("%d", &e);

        TERM = (POLY*)malloc(sizeof(POLY));
        TERM -> coef = c;
        TERM -> expo = e;
        TERM -> LINK = NULL;

        if(P == NULL)
            P = TERM;
        else
        {
            p = P;
            while(p -> LINK != NULL)
                p = p -> LINK;
            p -> LINK = TERM;
        }
    }

    // display
    p = P;
    printf("\nBegin -> ");
    while(p != NULL)
    {
        printf("(%d x ^ %d) -> ", p -> coef, p -> expo);
        p = p -> LINK;
    }
    printf("END\n");
}

void main()
{
    CREATE(5);
}