#include <stdio.h>
#include <math.h>

int main() {

    double x1, y1, z1;
    double x2, y2, z2;
    double distance;

    printf("Entrez les coordonnees du premier point (x1, y1, z1) : ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);

    printf("\nEntrez les coordonnees du deuxieme point (x2, y2, z2) : ");
    scanf("%lf %lf %lf", &x2, &y2, &z2);

    distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2) + pow((z2-z1),2));


    printf("La distance entre les deux points est : %.2lf\n", distance);

    return 0;
}

