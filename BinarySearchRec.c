#include <stdio.h>
int binary_search(int a[],int low, int high, int target)
{
    int i, flag = 0;
    if(high >= low)
    {
        int mid = (high + low)/2;
        if(a[mid] == target) return mid;
        else if(a[mid] < target) return binary_search(a,low,mid-1,target);
        else  return binary_search(a,mid+1,high,target);
    }
    return -1;
}

int main()
{
    int a[5] = {34,23,12,56,4}, target = 230, result;
    result = binary_search(a,0,5-1,target);
    if(result != -1) printf("Element found at %d", result);
    else printf("Element is not found");
}