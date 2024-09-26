#include <stdio.h>
#include <math.h>

int main() {
    int choix;
    double a, b, res;
    double Num[100];
    int n, i;

    do {
        printf("\n---- MENU DES OPETIONS ----\n");
        printf("1. Addition\n");
        printf("2. Soustraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Moyenne\n");
        printf("6. Valeur absolue\n");
        printf("7. Exponentiation\n");
        printf("8. Racine carree\n");
        printf("9. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                // Addition
                printf("Combien de nombres voulez-vous additionner ? ");
                scanf("%d", &n);
                res = 0;
                for (i = 0; i < n; i++) {
                    printf("Entrez le nombre %d : ", i + 1);
                    scanf("%lf", &Num[i]);
                    res += Num[i];
                }
                printf("Resultat de l'addition : %.2lf\n", res);
                break;

            case 2:
                // Soustraction
                printf("Entrez le premier nombre : ");
                scanf("%lf", &a);
                printf("Entrez le deuxieme nombre : ");
                scanf("%lf", &b);
                printf("Resultat de la soustraction : %.2lf\n", a - b);
                break;

            case 3:
                // Multiplication
                printf("Combien de nombres voulez-vous multiplier ? ");
                scanf("%d", &n);
                res = 1;
                for (i = 0; i < n; i++) {
                    printf("Entrez le nombre %d : ", i + 1);
                    scanf("%lf", &Num[i]);
                    res *= Num[i];
                }
                printf("Resultat de la multiplication : %.2lf\n", res);
                break;

            case 4:
                // Division
                printf("Entrez le premier nombre : ");
                scanf("%lf", &a);
                printf("Entrez le deuxieme nombre : ");
                scanf("%lf", &b);

                if (b != 0) {
                    printf("Resultat de la division : %.2lf\n", a / b);
                } else {
                    printf("La division par 0 est impossible!\n");
                }
                break;

            case 5:
                // Moyenne
                printf("Combien de nombres voulez-vous entrer pour la moyenne ? ");
                scanf("%d", &n);
                res = 0;
                for (i = 0; i < n; i++) {
                    printf("Entrez le nombre %d : ", i + 1);
                    scanf("%lf", &Num[i]);
                    res += Num[i];
                }
                printf("Resultat de la moyenne : %.2lf\n", res / n);
                break;

            case 6:
                // Valeur absolue
                printf("Entrez un nombre : ");
                scanf("%lf", &a);
                printf("Valeur absolue : %.2lf\n", fabs(a));
                break;

            case 7:
                // Exponentiation
                printf("Entrez le premier nombre : ");
                scanf("%lf", &a);
                printf("Entrez l'expo : ");
                scanf("%lf", &b);
                printf("Resultat de l'exponentiation : %.2lf\n", pow(a, b));
                break;

            case 8:
                // Racine carree
                printf("Entrez un nombre positif : ");
                scanf("%lf", &a);
                if (a < 0) {
                    printf("La racine carree d'un nombre negatif n'est pas definie.\n");
                } else {
                    printf("Resultat de la racine carree : %.2lf\n", sqrt(a));
                }
                break;

            case 9:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
        
    } while (choix != 9);

    return 0;
}
