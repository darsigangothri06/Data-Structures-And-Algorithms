#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LINK;
};

typedef struct TAG NODE;

NODE *FRONT = NULL, *REAR = NULL;

void Enqueue(int X)
{
    NODE *temp, *p;
    temp = (NODE*)malloc(sizeof(NODE));
    temp -> DATA = X;
    temp -> LINK = NULL;
    if(FRONT == NULL && REAR == NULL)
    {
        FRONT = temp;
        REAR = temp;
    }

    else
    {
        REAR -> LINK = temp;
        REAR = temp;
    }
    p = FRONT;
    printf("Begin -> ");
    while(p -> LINK != REAR)
    {
        printf("%d -> ", p -> DATA);
        p = p -> LINK;
    }
    printf("%u\n",p);
    printf("END\n");
}

int Dequeue()
{
    NODE *p;
    if(FRONT == NULL && REAR == NULL)
    {
        printf("Queue is Empty, Cannot remove\n");
        return -99;
    }
    else
    {
        int data;
        p = FRONT;
        data = p -> DATA;
        FRONT = FRONT -> LINK;
        p -> LINK = NULL;
        free(p);
    }
    p = FRONT;
    printf("Begin -> ");
    while(p -> LINK != REAR)
    {
        printf("%d -> ", p -> DATA);
        p = p -> LINK;
    }
    printf("%d -> ", p -> DATA);
    printf("END\n");
}

int main()
{
    Enqueue(100);
    Enqueue(10);
}