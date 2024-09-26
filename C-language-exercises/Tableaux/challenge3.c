#include <stdio.h>
int main()
{
    int i;
    int N;
    int Sum = 0;

    printf("Enrer le nombres des elements : ");
    scanf("%d", &N);

    int T[N];

    for ( i=0 ; i<N ; i++ )
    {
        printf("Enrer %d elements :", i + 1);
        scanf("%d", &T[i]);
        Sum += T[i];
    }
    printf("La somme des elements est : %d .", Sum);
    return 0;
}