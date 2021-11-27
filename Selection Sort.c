#include <stdio.h>

int main()
{
    int a[20],n,i,j,k,sl,temp;
    printf("\n Enter size of array: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++)
    {
        sl = i;
        for(k = i+1; k < n; k++)
        {
            if (a[k] < a[sl]) sl = k;
        }
        temp = a[sl];
        a[sl] = a[i];
        a[i] = temp;
    }
    printf("\n Sorted array using Selection sort is: ");
    for(i = 0; i < n; i++) printf("%5d",a[i]);

    return 0;
}
