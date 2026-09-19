#include <stdio.h>
#include <stdlib.h>

void push(int [], int *, int, int);
void pop(int [], int *);
void display(int [], int);

int main()
{
    int size;

    printf("Enter number of parcels\n");
    scanf("%d", &size);

    int *stack = malloc(sizeof(int) * size);
    int top = -1;
    int choice, parcelID;

    while (1)
    {
        printf("\n--- Parcel Storage System ---\n");
        printf("1. Add Parcel (Push)\n");
        printf("2. Remove Parcel (Pop)\n");
        printf("3. Display Parcels\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Parcel ID to add: ");
                scanf("%d", &parcelID);
                push(stack, &top, size, parcelID);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                display(stack, top);
                break;

            case 4:
                free(stack);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int stack[], int *top, int size, int parcelID)
{
    if (*top == size - 1)
        printf("Stack Overflow\n");
    else
    {
        (*top)++;
        stack[*top] = parcelID;
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
        printf("Stack Underflow!\n");
    else
    {
        printf("Parcel ID %d removed from stack\n", stack[*top]);
        (*top)--;
    }
}

void display(int stack[], int top)
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Parcels currently in storage:\n");

        for (int i = top; i >= 0; i--)
            printf("Parcel ID: %d\n", stack[i]);
    }
}
