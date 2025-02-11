/* Reverse Array in C */
#include <stdio.h>
void main()
{
    int temp;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start=0,end=size-1;
    while (start < end) 
    {
        // Swap elements at start and end indices
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // Move towards the center
        start++;
        end--;
    }
    printf("After revrsing Array::\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
}
