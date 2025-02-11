//Sorting Techniques in C
#include <stdio.h>
void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-i-1; j++) 
		{
            if (arr[j] > arr[j+1]) 
			{
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(int arr[], int n) 
{
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) 
	{
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void display(int arr[], int size) 
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() 
{
	int n,i,arr[n];

    printf("\nENter size of array:\n");
    scanf("%d",&n);
    printf("Enter Array elements:\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    printf("Unsorted array: \n");
    display(arr, n);
    

    bubbleSort(arr, n);
    printf("Sorted array using Bubble Sort: \n");
    display(arr, n);
   

    insertionSort(arr, n);
    printf("Sorted array using Insertion Sort: \n");
    display(arr, n);
    

    selectionSort(arr, n);
    printf("Sorted array using Selection Sort: \n");
    display(arr, n);

}
