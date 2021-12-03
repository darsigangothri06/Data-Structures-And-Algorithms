#include <stdio.h>
void main()
{
    int a[5] = {12,34,23,5,6}, i, flag = 0, target = 23;
    for(i = 0; i < 5; i++)
    {
        if(a[i] == target)
        {
            flag = 1;
            printf("Element found at position %d", i);
            break;
        }
    }
    if(flag == 0) printf("Element is not found.");
}