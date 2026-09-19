#include <stdio.h>
#include <stdlib.h>

struct employee {
    int ssn;
    char name[50], dept[50], desig[50], phone[15];
    float salary;
    struct employee *prev, *next;
};

struct employee* create() {
    struct employee *p = malloc(sizeof(struct employee));

    printf("enter the ssn:\n");
    scanf("%d", &p->ssn);
    printf("enter the name:\n");
    scanf("%s", p->name);
    printf("enter the departement:\n");
    scanf("%s", p->dept);
    printf("enter the designation:\n");
    scanf("%s", p->desig);
    printf("enter the salary:\n");
    scanf("%f", &p->salary);
    printf("enter the phone number:\n");
    scanf("%s", p->phone);

    p->prev = p->next = NULL;
    return p;
}

struct employee* insertfront(struct employee *head) {
    struct employee *p = create();

    if (head) {
        p->next = head;
        head->prev = p;
    }
    return p;
}

struct employee* insertrear(struct employee *head) {
    struct employee *p = create(), *t;

    if (!head) return p;

    t = head;
    while (t->next)
        t = t->next;

    t->next = p;
    p->prev = t;

    return head;
}

struct employee* deletefront(struct employee *head) {
    struct employee *t;

    if (!head) {
        printf("list is empty\n");
        return NULL;
    }

    t = head;
    head = head->next;

    if (head)
        head->prev = NULL;

    printf("deleted employee : %s\n", t->name);
    free(t);

    return head;
}

struct employee* deleterear(struct employee *head) {
    struct employee *t;

    if (!head) {
        printf("list is empty\n");
        return NULL;
    }

    t = head;
    while (t->next)
        t = t->next;

    printf("deleted employee : %s\n", t->name);

    if (t->prev)
        t->prev->next = NULL;
    else
        head = NULL;

    free(t);
    return head;
}

void display(struct employee *head) {
    struct employee *t = head;
    int count = 0;

    if (!head) {
        printf("list is empty\n");
        return;
    }

    while (t) {
        printf("name : %s  | ssn : %d   |department : %s   | designation : %s  |salary: %f   |phone : %s\n",
               t->name, t->ssn, t->dept, t->desig,
               t->salary, t->phone);
        t = t->next;
        count++;
    }

    printf("number of nodes :%d\n", count);
}

int main() {
    struct employee *head = NULL;
    int choice;

    do {
        printf("\n------employee details------\n");
        printf("1.insert at front\n");
        printf("2.insert at rear\n");
        printf("3.delete at front\n");
        printf("4.delete at rear\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("enter the choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = insertfront(head); break;
            case 2: head = insertrear(head); break;
            case 3: head = deletefront(head); break;
            case 4: head = deleterear(head); break;
            case 5: display(head); break;
            case 6: printf("exit\n"); break;
            default: printf("invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
