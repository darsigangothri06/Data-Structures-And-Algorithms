#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE *START = NULL;

void CREATE(int X)
{
    NODE *TEMP, *p;

    TEMP = (NODE*)malloc(sizeof(NODE));
    TEMP -> DATA = X;
    TEMP -> LINK = START;

    if(START == NULL) 
    {
        START = TEMP;
        START -> LINK = START;
    }
    else
    {
        p = START;
        while(p -> LINK != START)
            p = p -> LINK;
        p -> LINK = TEMP;
    }
}

void DeleteAtEnd()
{
    NODE *p, *q = NULL;
    if(START == NULL) printf("\nNo Nodes to delete");
    else
    {
        p = START;
        while(p -> LINK != START)
        {
            q = p;
            p = p -> LINK;
        }
        q -> LINK = START;
        p -> LINK = NULL;
        printf("%d is deleted", p -> DATA);
        free(p);
    }
}

void DISPLAY()
{
    NODE *p = START;
    printf("\nBEGIN -> ");
    while(p -> LINK != START)
    {
        printf("%d ->", p -> DATA);
        p = p -> LINK;
    }
    printf("%d -> END\n", p -> DATA);
}

void main()
{
    CREATE(10);
    CREATE(20);
    CREATE(30);
    CREATE(40);
    CREATE(50);
    DISPLAY();
    DeleteAtEnd();
    DISPLAY();
    DeleteAtEnd();
    DISPLAY();
}