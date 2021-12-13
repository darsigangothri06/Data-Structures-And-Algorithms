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

int Count(NODE *START)
{
    int cnt = 1;
    NODE *p = START;
    if(START == NULL) return 0;
    while(p -> LINK != NULL)
    {
        p = p -> LINK;
        cnt++;
    }
    return cnt;
}

int main()
{
    int POS, X;
    NODE *G;
    printf("Enter DATA: ");
    scanf("%d", &X);
    printf("Enter Position: ");
    scanf("%d", &POS);
    if(POS == 0)
    {
        G = ADD_AT_BEGIN(NULL,X);
        printf("Adding at begin: ", G);
    }
    else if(POS == Count(NULL))
    {
        G = ADD_AT_BEGIN(NULL,X);
        G = ADD_AT_END(G, X);
        printf("Adding at end: ", G);
    }
    else if(POS > Count(NULL)) printf("\n Cannot add");
    else
    {
        G = Add_AT_POS(NULL,12,2);
        printf("Adding at position: ", G);
    }
    return 0;

}