#include <stdio.h>
#include <stdlib.h>

struct Student {
    char usn[15], name[30], prog[20], phone[15];
    int sem;
    struct Student *next;
};

struct Student *create() {
    struct Student *p = malloc(sizeof(struct Student));

    printf("Enter USN: ");
    scanf("%s", p->usn);
    printf("Enter Name: ");
    scanf(" %[^\n]", p->name);
    printf("Enter Programme: ");
    scanf(" %[^\n]", p->prog);
    printf("Enter Semester: ");
    scanf("%d", &p->sem);
    printf("Enter Phone: ");
    scanf("%s", p->phone);

    p->next = NULL;
    return p;
}

struct Student *front(struct Student *head) {
    struct Student *p = create();
    p->next = head;
    return p;
}

struct Student *end(struct Student *head) {
    struct Student *p = create(), *t;

    if (head == NULL) return p;

    t = head;
    while (t->next)
        t = t->next;

    t->next = p;
    return head;
}

struct Student *delfront(struct Student *head) {
    struct Student *t;

    if (!head) {
        printf("List is empty!\n");
        return NULL;
    }

    t = head;
    head = head->next;
    printf("Deleted: %s\n", t->name);
    free(t);

    return head;
}

struct Student *delend(struct Student *head) {
    struct Student *t, *p;

    if (!head) {
        printf("List is empty!\n");
        return NULL;
    }

    if (!head->next) {
        printf("Deleted: %s\n", head->name);
        free(head);
        return NULL;
    }

    p = head;
    while (p->next->next)
        p = p->next;

    t = p->next;
    p->next = NULL;

    printf("Deleted: %s\n", t->name);
    free(t);

    return head;
}

void display(struct Student *head) {
    struct Student *p = head;
    int count = 0;

    if (!head) {
        printf("No student records!\n");
        return;
    }

    while (p) {
        printf("\nUSN: %s\nName: %s\nProgramme: %s\nSemester: %d\nPhone: %s\n",
               p->usn, p->name, p->prog, p->sem, p->phone);
        count++;
        p = p->next;
    }

    printf("\nTotal Students = %d\n", count);
}

int main() {
    struct Student *head = NULL;
    int ch, n, i;

    while (1) {
        printf("\n--- Student Management ---\n");
        printf("1. Create N Students\n");
        printf("2. Display Students\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete from Front\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    head = front(head);
                break;

            case 2: display(head); break;
            case 3: head = end(head); break;
            case 4: head = delend(head); break;
            case 5: head = front(head); break;
            case 6: head = delfront(head); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
