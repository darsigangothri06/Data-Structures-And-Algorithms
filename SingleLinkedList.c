#include <stdio.h>
#include <stdlib.h>

// Defining Node
struct TAG
{
    int DATA;
    struct TAG *LINK; // SELF REFERENTIAL STRUCTURE
};

// Giving a new name to struct TAG as NODE
typedef struct TAG NODE;

// Creating Linkedlist with N nodes and START as start pointer
NODE *CREATE(NODE *START, int N)
{
    int i, X;
    NODE *p, *TEMP;
    for(i = 1; i <= N; i++)
    {
        printf("\nEnter Data of %dth node: ", i);
        scanf("%d", &X);

        //Create TEMP NODE with DATA X
        TEMP = (NODE*)malloc(sizeof(NODE));
        TEMP -> DATA = X;  //Assigning the value of X to Data in Node
        TEMP -> LINK = NULL;  // Temp points to NULL

        // If temp is starting node, then START should point to TEMP
        if(START == NULL) START = TEMP;
        else  // If TEMP is not starting node, then we have to add TEMP to end of the linked list
        {
            p = START;
            while(p -> LINK != NULL) p = p -> LINK;   // Moving the pointer p forward to next node
            p -> LINK = TEMP;  // When pointer comes to last node, LINK == NULL. Then we have to set it's NULL to TEMP to add the link
        }
    }
    return START;  // returning the START value of the linkedlist
}

void main()
{
    int X;
    printf("\nEnter No: of nodes to add: ");
    scanf("%d", &X);
    printf("\nStarting address of your LinkedList is: %u",CREATE(NULL,X));  // At Starting, START should point to NULL
}