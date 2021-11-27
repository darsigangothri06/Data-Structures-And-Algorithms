#include <stdio.h>

int main() {
    int a[8] = {10,34,78,89,211,250,300,350}, target = 211,low,high,mid,flag = 0;
    if(a[0] ==  target) printf("Found at 0");
    else if (a[8-1] == target) printf("Found at last");
    else
    {
        low = 1;
        high = 8-1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if (a[mid] == target)
            {
                flag = 1;
                printf("Found at %d",mid);
                break;
            }
            else if(a[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
    }
    if (flag == 0) printf("Element not found");
    return 0;
}