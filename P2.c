#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n = 1000;
    int arr[1000];
    int choice, i;
    printf("1. Best Case\n");
    printf("2. Average Case\n");
    printf("3. Worst Case\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // Best Case
        {
            for(i = 0; i < n; i++)
                arr[i] = i;

            clock_t start = clock();
            selectionSort(arr, n);
            clock_t end = clock();

            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Best Case Time: %f seconds\n", time_taken);
            break;
        }

        case 2: // Average Case
        {
            for(i = 0; i < n; i++)
                arr[i] = rand() % 1000;

            clock_t start = clock();
            selectionSort(arr, n);
            clock_t end = clock();

            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Average Case Time: %f seconds\n", time_taken);
            break;
        }

        case 3: // Worst Case
        {
            for(i = 0; i < n; i++)
                arr[i] = n - i;

            clock_t start = clock();
            selectionSort(arr, n);
            clock_t end = clock();

            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Worst Case Time: %f seconds\n", time_taken);
            break;
        }

        default:
            printf("Invalid Choice");
    }

    return 0;
}
