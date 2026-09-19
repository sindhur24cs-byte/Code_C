#include <stdio.h>
#include <string.h>

struct day
{
    char name[10];
    int date;
    char activity[50];
};

typedef struct day Day;

void create(Day planner[], int size);
void read(Day planner[], int size);
void display(Day planner[], int size);

int main()
{
    #define SZ 3

    Day planner[SZ];

    create(planner, SZ);
    read(planner, SZ);
    display(planner, SZ);

    return 0;
}

void create(Day planner[], int size)
{
    for (int i = 0; i < size; i++)
    {
        strcpy(planner[i].name, "");
        planner[i].date = 0;
        strcpy(planner[i].activity, "");
    }
}

void read(Day planner[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Day %d:\n", i + 1);

        printf("Enter day name: ");
        scanf("%s", planner[i].name);

        printf("Enter date (numeric): ");
        scanf("%d", &planner[i].date);

        printf("Enter activity: ");
        scanf("%s", planner[i].activity);
    }
}

void display(Day planner[], int size)
{
    printf("\n=== Weekly Activity Report ===\n");

    printf("%-10s %-6s %-30s\n", "Day", "Date", "Activity");

    printf("----------------------------------------------\n");

    for (int i = 0; i < size; i++)
    {
        printf("%-10s %-6d %-30s\n",
               planner[i].name,
               planner[i].date,
               planner[i].activity);
    }
}
