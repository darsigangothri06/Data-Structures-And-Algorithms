#include <stdio.h>
#include <stdlib.h>

// Incorrect Output
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

void AddPoly()
{
    POLY *TERM, *p = P, *q = Q, *r = R;
    while(p != NULL && q != NULL)
    {
        printf("\n in for %d %d %d %d", p -> coef, p -> expo, q -> coef, q -> expo);
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
            TERM -> coef = q -> coef;
            TERM -> expo = q -> expo;
            TERM -> LINK = NULL;

            //moving q
            q = q -> LINK;
        }
        else
        {
            TERM -> coef = p -> coef + q -> coef;
            TERM -> expo = p -> expo;
            TERM -> LINK = NULL;

            // moving p and q
            p = p -> LINK;
            q = q -> LINK;
        }

        if(R == NULL) 
        {
            R = TERM;
            r = TERM;
        }

        else
            r -> LINK = TERM;
    }
    // remaining terms of P
    while(p != NULL)
    {
        TERM = (POLY*)malloc(sizeof(POLY));
        TERM -> coef = p -> coef;
        TERM -> expo = p -> expo;
        TERM -> LINK = NULL;
        r -> LINK = NULL;
        p = p -> LINK;
    }

    while(q != NULL)
    {
        TERM = (POLY*)malloc(sizeof(POLY));
        TERM -> coef = q -> coef;
        TERM -> expo = q -> expo;
        TERM -> LINK = NULL;
        r -> LINK = NULL;
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

    AddPoly();

    p = P;
    printf("\nP(x) = ");
    while(p != NULL)
    {
        printf("(%d x ^ %d) + ", p ->coef, p -> expo);
        p = p -> LINK;
    }
    printf("\n");

    q = Q;
    printf("\nQ(x) = ");
    while(q != NULL)
    {
        printf("(%d x ^ %d) + ", q ->coef, q -> expo);
        q = q -> LINK;
    }
    
}