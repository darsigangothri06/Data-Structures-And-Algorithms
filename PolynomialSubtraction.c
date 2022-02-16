#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int coef;
    int expo;
    struct TAG *LINK;
};

typedef struct TAG POLY;

POLY *P = NULL, *Q = NULL, *R = NULL, *r = NULL;

void CreateFirst(int C, int E)
{
    POLY *TERM, *p;
    TERM = (POLY*)malloc(sizeof(POLY));
    TERM -> coef = C;
    TERM -> expo = E;
    TERM -> LINK = NULL;

    if(P == NULL) P = TERM;
    else
    {
        p = P;
        while(p -> LINK != NULL) p = p -> LINK;
        p -> LINK = TERM;
    }
}

void CreateSecond(int C, int E)
{
    POLY *TERM, *q;
    TERM = (POLY*)malloc(sizeof(POLY));
    TERM -> coef = C;
    TERM -> expo = E;
    TERM -> LINK = NULL;

    if(Q == NULL) Q = TERM;
    else
    {
        q = Q;
        while(q -> LINK != NULL) q = q -> LINK;
        q -> LINK = TERM;
    }
}

void SubtractPoly()
{
    POLY *TERM, *p = P, *q = Q;
    while(p != NULL && q != NULL)
    {
        TERM = (POLY*)malloc(sizeof(POLY));
        if(p -> expo > q -> expo)
        {
            TERM -> coef = p -> coef;
            TERM -> expo = p -> expo;
            TERM -> LINK = NULL;

            // moving p 
            p = p -> LINK;
        }
        else if(q -> expo > p -> expo)
        {
            TERM -> coef = 0 - q -> coef;  // CHANGE
            TERM -> expo = q -> expo;
            TERM -> LINK = NULL;

            //moving q
            q = q -> LINK;
        }
        else
        {
            TERM -> coef = p -> coef - q -> coef;  // CHANGE
            TERM -> expo = p -> expo;
            TERM -> LINK = NULL;

            // moving p and q
            p = p -> LINK;
            q = q -> LINK;
        }

        if(R == NULL) 
            R = TERM;

        else
        {
            r = R;
            while(r -> LINK != NULL) r = r -> LINK;
            r -> LINK = TERM;
        }
    }
    // remaining terms of P
    while(p != NULL)
    {
        TERM = (POLY*)malloc(sizeof(POLY));
        TERM -> coef = p -> coef;
        TERM -> expo = p -> expo;
        TERM -> LINK = NULL;
        
        r = R;
        while(r -> LINK != NULL) r = r -> LINK;
        r -> LINK = TERM;

        p = p -> LINK;
    }

    while(q != NULL)
    {
        TERM = (POLY*)malloc(sizeof(POLY));
        TERM -> coef = 0 - q -> coef;  // CHANGE 
        TERM -> expo = q -> expo;
        TERM -> LINK = NULL;

        r = R;
        while(r -> LINK != NULL) r = r -> LINK;
        r -> LINK = TERM;

        q = q -> LINK;
    }
}

void main()
{
    POLY *p = P, *q = Q, *r = R;
    CreateFirst(2,2);

    CreateSecond(2,3);
    CreateSecond(2,1);
    CreateSecond(4,0);

    SubtractPoly();

    p = P;
    printf("\nP(x) = ");
    while(p != NULL)
    {
        printf(" + (%d x ^ %d) ", p ->coef, p -> expo);
        p = p -> LINK;
    }
    printf("\n");

    q = Q;
    printf("\nQ(x) = ");
    while(q != NULL)
    {
        printf(" + (%d x ^ %d)", q ->coef, q -> expo);
        q = q -> LINK;
    }

    q = R;
    printf("\nR(x) = ");
    while(q != NULL)
    {
        printf(" + (%d x ^ %d)", q ->coef, q -> expo);
        q = q -> LINK;
    }
    
}