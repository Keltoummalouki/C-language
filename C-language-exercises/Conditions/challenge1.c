#include <stdio.h>

int main() {
    int Num;

    printf("Entrer un nombre: ");
    scanf("%d", &Num);

    if (Num % 2 == 0) {
        printf("Le nombre %d est pair.\n", Num);
    } else {
        printf("Le nombre %d est impair.\n", Num);
    }

    return 0;
}
