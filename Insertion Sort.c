#include <stdio.h>

int main()
{
    int a[20],n, i, j, v;
    printf("Enter size of array: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    for(i = 1; i < n; i++)
    {
        v = a[i];
        j = i;
        while(j && a[j-1]>v) 
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
    printf("\n Sorted Array using Insertion Sort is: ");
    for(i=0;i<n;i++) printf("%5d",a[i]);

    return 0;
}
