#include <stdio.h>
void MergeSort(int a[],int,int);
void Merge(int a[],int,int,int);
int main()
{
    int a[9] = {19,23,45,2,6,9,1,10,0},n = 9, i,j,mid;
    mid = n/2;
    MergeSort(a,0,n-1);
    for(i = 0; i < n; i++) printf("%5d",a[i]);
    return 0;
}
void MergeSort(int a[],int low, int high)
{
    if (high > low)
    {
        int mid = (low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,mid,low,high);
    }
}
void Merge(int a[],int mid, int low, int high)
{
    int c[20],i,j,k;
    i = low;
    j = mid + 1;
    k = low;
    while(i <= low && j <= high)
    {
        if (a[i] < a[j]) c[k++] = a[i++];
        else if (a[i] > a[j]) c[k++] = a[j++];
        else c[k++] = a[i++];
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= high) c[k++] = a[j++];
    for(i = 0; i <= high; i++) a[i] = c[i];
}

