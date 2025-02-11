//Binary Search program using binarySearch Function
#include <stdio.h>

int binarySearch(int arr[], int size, int key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) 
        {
            return mid; // Return the index if found
        }
        else if (arr[mid] < key) 
        {
            low = mid + 1; // Discard left half
        } 
        else 
        {
            high = mid - 1; // Discard right half
        }
    }
    return -1; // Return -1 if not found
}

void main() 
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, result;

    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    // Binary search
    result = binarySearch(arr, size, key);

    if (result != -1) 
    {
        printf("Element found at index: %d\n", result);
    } 
    else 
    {
        printf("Element not found\n");
    }
}
