#include <stdio.h>
#include <string.h>

int slen(char *);
void replace(char *, char *, char *, char *);

int main()
{
    char T[100];
    char P[50];
    char REP[50];
    char FIN[200];

    printf("Enter Main string: ");
    scanf("%s", T);

    printf("Enter Pattern string: ");
    scanf("%s", P);

    printf("Enter Replacement string: ");
    scanf("%s", REP);

    replace(T, P, REP, FIN);

    printf("Output: %s\n", FIN);

    return 0;
}

int slen(char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

void replace(char *T, char *P, char *REP, char *FIN)
{
    int k = 0;
    int s = slen(T);
    int r = slen(P);
    int q = 0;
    int e;
    int z;
    int repLen = slen(REP);

    while (k < s)
    {
        for (e = 0; e < r; e++)
        {
            if (T[k + e] != P[e])
                break;
        }

        if (e == r)
        {
            for (z = 0; z < repLen; z++)
                FIN[q++] = REP[z];

            k += r;
        }
        else
        {
            FIN[q++] = T[k++];
        }
    }

    FIN[q] = '\0';
}
