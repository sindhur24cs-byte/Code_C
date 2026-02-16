#include <stdio.h>

int main() {

    int roll;
    char name[50];
    float marks;

    // Input
    printf("Enter Student Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Student Name: ");
    scanf("%s", name);

    printf("Enter Student Marks: ");
    scanf("%f", &marks);

    // Output
    printf("\n--- Student Details ---\n");
    printf("Roll Number : %d\n", roll);
    printf("Name        : %s\n", name);
    printf("Marks       : %.2f\n", marks);

    return 0;
}
