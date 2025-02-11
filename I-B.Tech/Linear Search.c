//Linear Search in C
#include <stdio.h>
void main()
{
    int arr[10],n,key,i;
    printf("Enter number of elements in array:\n");
    scanf("%d",&n);
    printf("Enter array integers");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear search
    for (i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            printf("Element %d found at index: %d\n", key,i);
            break; // Stop searching once the element is found
        }
    }
    if (i==n) {
        printf("Element not present in Array\n");
    }
}
