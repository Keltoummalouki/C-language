#include <stdio.h>

int main() {
    float annee;
    int choix;


    printf("Entrez le nombre d'annees : ");
    scanf("%f", &annee);
    printf("Choisissez une option : \n");
    printf("1. Convertir en mois\n");
    printf("2. Convertir en jours\n");
    printf("3. Convertir en heures\n");
    printf("4. Convertir en minutes\n");
    printf("5. Convertir en secondes\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("%.0f ann�es = %.0f mois\n", annee, annee * 12);
            break;
        case 2:
            printf("%.0f ann�es = %.0f jours\n", annee, annee * 365);
            break;
        case 3:
            printf("%.0f ann�es = %.0f heures\n", annee, annee * 365 * 24);
            break;
        case 4:
            printf("%.0f ann�es = %.0f minutes\n", annee, annee * 365 * 24 * 60);
            break;
        case 5:
            printf("%.0f ann�es = %.0f secondes\n", annee, annee * 365 * 24 * 60 * 60);
            break;
        default:
            printf("Choix invalide, veuillez ressayer.\n");
            break;
    }

    return 0;
}
