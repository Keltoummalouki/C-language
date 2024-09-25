#include <stdio.h>

int main() {
    int a, b;
    int Sum;
    int Res;

    printf("Entrez la premiere valeur: ");
    scanf("%d", &a);
    printf("Entrez la deuxieme valeur: ");
    scanf("%d", &b);


    Sum = a + b;

    if (a == b) {
        Res = Sum * 3;
    }

    printf("Le resultat est: %d\n", Res);

    return 0;
}
