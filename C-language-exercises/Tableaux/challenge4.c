#include <stdio.h>
int main()
{
    int i;
    int N;
    int G;

    printf("Enrer le nombres des elements : ");
    scanf("%d", &N);

    int T[N];
    for ( i=0 ; i<N ; i++ )
    {
        printf("Enrer %d elements :", i + 1);
        scanf("%d", &T[i]);
    }
    G = T[0];
    for ( i=0 ; i<N ; i++ )
    {
        if (T[i]>G)
        G = T[i];

    }
    printf("Le plus grand element est : %d .", G);
    return 0;
}