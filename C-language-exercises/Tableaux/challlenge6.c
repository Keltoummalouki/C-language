#include <stdio.h>
int main()
{
    int i;
    int N;
    int F;
    int Sum = 1;

    printf("Enrer le nombres des elements : ");
    scanf("%d", &N);

    printf("Enrer un facteur de multiplication : ");
    scanf("%d", &F);

    int T[N];

    for ( i=0 ; i<N ; i++ )
    {
        printf("Enrer %d elements :", i + 1);
        scanf("%d", &T[i]);
      
    }
for ( i=0 ; i<N ; i++ )
    {
         printf("%d\n",T[i] * F); 
      
    }

   
    
    return 0;
}