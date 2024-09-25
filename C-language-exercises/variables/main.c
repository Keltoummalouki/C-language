#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Km,yards;

    printf("Enter distance in kilometres : ");
    scanf("%f" , Km);

    yards = Km * 1093.61 ;

    printf("Distance in yards is : %f ", yards);


    return 0;
}
