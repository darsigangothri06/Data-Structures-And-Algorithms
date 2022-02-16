#include <stdio.h>
#include <stdlib.h>

// no R(x)
struct TAG
{
    int coef;
    int expo;
    struct TAG *LINK;
};

typedef struct TAG POLY;

POLY *P = NULL, *Q = NULL, *R = NULL;

void CreateFirst(int C, int E)
{
    POLY *TERM, *p;
    TERM = (POLY*)malloc(sizeof(POLY));
    TERM -> coef = C;
    TERM -> expo = E;
    TERM -> LINK = NULL;

    if(P == NULL) p = TERM;
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

void AddPoly()
{
    POLY *TERM, *p = P, *q = Q, *r;
    TERM = (POLY*)malloc(sizeof(POLY));
    while(p != NULL && q != NULL)
    {
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
            TERM -> coef = q -> coef;
            TERM -> expo = q -> expo;
            TERM -> LINK = NULL;

            //moving q
            q = q -> LINK;
        }
        else if(p -> expo == q -> expo)
        {
            TERM -> coef = p -> coef + q -> coef;
            TERM -> expo = p -> expo;
            TERM -> LINK = NULL;

            // moving p and q
            p = p -> LINK;
            q = q -> LINK;
        }

        if(R == NULL) R = TERM;
        else
        {
            r = R;
            while(r -> LINK != NULL) r = r -> LINK;
            r -> LINK = TERM;
        }

        // remaining terms of P
        while(p != NULL)
        {
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
            TERM -> coef = q -> coef;
            TERM -> expo = q -> expo;
            TERM -> LINK = NULL;

            r = R;
            while(r -> LINK != NULL) r = r -> LINK;
            r -> LINK = TERM;

            q = q -> LINK;
        }
    }

    r = R;
    printf("R(x) = ");
    while(r != NULL)
    {
        printf("(%d x ^ %d) + ", r ->coef, r -> expo);
        r = r -> LINK;
    }
}

void main()
{
    CreateFirst(2,2);
    CreateFirst(5,1);
    CreateFirst(4,0);

    CreateSecond(2,2);
    CreateSecond(5,1);
    CreateSecond(4,0);

    AddPoly();
}