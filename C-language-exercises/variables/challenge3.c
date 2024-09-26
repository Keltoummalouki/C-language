#include <stdio.h>
int main()
{

    float Km; // Kilometres
    float Y; // Yards

    printf("Entrer la distance en kilometres : ");
    scanf("%f", &Km);

    Y = Km * 1093.61;

    printf("La distance en yards est : %.2f\n", Y );


    return 0;
}