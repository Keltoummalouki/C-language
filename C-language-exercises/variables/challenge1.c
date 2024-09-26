#include <stdio.h>
int main()
{

    char Prenom[40];
    char Nom[40];
    int Age;
    char Sexe;
    char Email[100];



    printf("Entrer votre prenom : ");
        scanf("%s",Prenom);

    printf("\nEntrer votre nom : ");
        scanf("%s",Nom);

    printf("\nEntrer votre age : ");
        scanf("%d", &Age);

    printf("\nEntrer votre sexe (F/M) : ");
        scanf(" %c", &Sexe);

    printf("\nEntrer votre email : ");
        scanf("%s", Email);

    printf("Bonjour %s %s" ,Prenom, Nom);
    printf(",vous avez %d ans" ,Age);
    printf(",vous etes %c" ,Sexe);
    printf(",votre email est %s." ,Email);


    return 0;
}