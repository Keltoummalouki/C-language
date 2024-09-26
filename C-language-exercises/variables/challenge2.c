#include <stdio.h>
int main()
{

    float C; // Celsius
    float K; // Kelvin

    printf("Entrer la temperature en Celsius : ");
    scanf("%f", &C);

    K = C + 273.15;

    printf("La temperature en Kelvin est : %.2f\n", K );


    return 0;
}