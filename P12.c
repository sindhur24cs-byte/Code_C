#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char isbn[14];
    char title[40];
    struct tree *left;
    struct tree *right;
} TNODE;

TNODE *insert(TNODE *root)
{
    TNODE *p;
    TNODE *t;
    int n,i;

    printf("Enter number of nodes\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p = malloc(sizeof(TNODE));

        printf("Enter ISBN and Book-Title:\n");
        scanf("%s %s", p->isbn, p->title);

        p->left = NULL;
        p->right = NULL;

        if(root == NULL)
        {
            root = p;
            continue;
        }

        t = root;

        while(1)
        {
            if(strcmp(p->isbn, t->isbn) == 0)
            {
                printf("Redundant data\n");
                free(p);
                break;
            }

            if(strcmp(p->isbn, t->isbn) < 0)
            {
                if(t->left == NULL)
                {
                    t->left = p;
                    break;
                }

                t = t->left;
            }
            else
            {
                if(t->right == NULL)
                {
                    t->right = p;
                    break;
                }

                t = t->right;
            }
        }
    }

    return root;
}

void inorder(TNODE *root)
{
    if(root != NULL)
    {
        inorder(root->left);

        printf("%s:%s\n", root->isbn, root->title);

        inorder(root->right);
    }
}

void preorder(TNODE *root)
{
    if(root != NULL)
    {
        printf("%s:%s\n", root->isbn, root->title);

        preorder(root->left);

        preorder(root->right);
    }
}

void postorder(TNODE *root)
{
    if(root != NULL)
    {
        postorder(root->left);

        postorder(root->right);

        printf("%s:%s\n", root->isbn, root->title);
    }
}

int search(TNODE *root, char *key)
{
    if(root == NULL)
        return 0;

    if(strcmp(key, root->isbn) == 0)
        return 1;

    if(strcmp(key, root->isbn) < 0)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    TNODE *root = NULL;

    int choice;

    char isbn[14];

    while(1)
    {
        printf("Enter\n");

        printf("1. Insert\n");

        printf("2. Inorder\n");

        printf("3. Preorder\n");

        printf("4. Postorder\n");

        printf("5. Search\n");

        printf("6. Exit\n");

        printf("Choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                root = insert(root);
                break;

            case 2:
                printf("Inorder Traversal\n");

                if(root == NULL)
                    printf("Tree is empty\n");
                else
                    inorder(root);

                break;

            case 3:
                printf("Preorder Traversal\n");

                if(root == NULL)
                    printf("Tree is empty\n");
                else
                    preorder(root);

                break;

            case 4:
                printf("Postorder Traversal\n");

                if(root == NULL)
                    printf("Tree is empty\n");
                else
                    postorder(root);

                break;

            case 5:
                printf("Enter the node to be searched:\n");

                scanf("%s", isbn);

                if(search(root, isbn))
                    printf("Successful search!!!\n");
                else
                    printf("Unsuccessful search!!!\n");

                break;

            case 6:
                exit(0);
        }
    }

    return 0;
}
