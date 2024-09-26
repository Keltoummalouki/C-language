#include <stdio.h>
int main()
{
    int N;
    int i;

    printf("Entrer un nombre d'elements de tableau : ");
    scanf("%d", &N);

    int T[N];

    for (i=0;i<N;i++)
    {
        printf("Saisir les element %d : ", i + 1);
        scanf("%d", &T[i]);
    }
    printf("les elements du tableau est : \n");
    for (i=0;i<N;i++)
    {
        printf("%d\n", T[i]);
    }
    


    return 0;
}