#include <stdio.h>
# Bubble sort - Ascending Order
int main()
{
    int a[20],i,j,temp,n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nSorted array is: \n");
    for(i=0;i<n;i++) printf("%5d",a[i]);

    return 0;
}
