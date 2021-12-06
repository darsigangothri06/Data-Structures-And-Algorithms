#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int Q[SIZE], front = -1, rear = -1;
void ENQUEUE(int);
int DEQUEUE();
void DISPLAY();
int ISEMPTY();
int ISFULL();
void main()
{
    int flag, X, choice;
    while(1)
    {
        printf("\n\n----------------Operations in Oridinary Queue-------------\n1. Enqueue\n2. Dequeue\n3. Display\n4. Is Empty\n5. Is Full\n6. Exit\nEnter your option here: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                    {
                        printf("Enter an element to add into queue: ");
                        scanf("%d", &X);
                        ENQUEUE(X);
                        break;
                    }
            case 2: 
                    {
                        X = DEQUEUE();
                        if(X == -999)
                        {
                            printf("\nYour Queue is Empty, Add any element.");
                            break;
                        }
                        else
                        {
                            printf("%d Removed from Queue", X);
                            break;
                        }
                    }
            case 3:
                    {
                        DISPLAY();
                        break;
                    }
            case 4:
                    {
                        flag = ISEMPTY();
                        if(flag == 1) printf("\nYour Queue is empty.");
                        else printf("\nYour Queue is not empty.");
                        break;
                    }
            case 5:
                    {
                        flag = ISFULL();
                        if(flag == 1) printf("\nYour Queue is full.");
                        else printf("\nYour Queue is not full.");
                        break;
                    }
            case 6:
                    {
                        exit(1);
                    }
        }
    }
}

void ENQUEUE(int X)
{
    if((front == 0) && (rear == SIZE -1)) printf("\nYour Queue is Full, Underflow");
    else
    {
        rear += 1;
        Q[rear] = X;
        if(front == -1) front += 1; // If X is the first element to add into Queue.
    }
}

int DEQUEUE()
{
    int X;
    if((front == -1) && (rear == -1)) X = -999;
    else
    {
        X = Q[front];
        if(front == rear) // If there is only single element in Queue
        {
            front = -1;
            rear = -1;   // Setting the value of rear and front to -1 --- Queue is empty after deleting the single element
        }
        else front += 1;
    }
    return X;
}

void DISPLAY()
{
    int i;
    if((front == -1) && (rear == -1)) printf("\nYour Queue is Empty, nothing to display");
    else
    {
        printf("\n------------Your Queue is-------------\n");
        for(i = front; i <= rear; i++) printf("%5d", Q[i]);
        printf("\n");
    }
}

int ISEMPTY()
{
    if((front == -1) && (rear == -1)) return 1;
    return 0;
}

int ISFULL()
{
    if((front == 0) && (rear == SIZE -1)) return 1;
    return 0;
}