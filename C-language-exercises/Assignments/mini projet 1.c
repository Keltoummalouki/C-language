#include <stdio.h>
int main()
{
    char title[50][50];
    char auteur[50][50];
    float price[50][50];
    int quantity[50][50];
    int stock = 0;
    int choice;
    int i , n;

        do
        {
                        printf("\n\n-----------------Menu-----------------\n");
                        printf("1 - Ajouter un livre.\n");
                        printf("2 - Afficher les livres disponible.\n");
                        printf("3 - Chercher un livre par son titre.\n");
                        printf("4 - Mise a jour des information d'un livre.\n");
                        printf("5 - Supprimer un livre.\n");
                        printf("6 - Calculer le stock des livres disponible.\n");
                        printf("7 - Quitter\n");
                        printf("Soisissez votre choix  : ");
                        scanf("%d", &choice);

            switch(choice)
            {
                case 1 :
                    for ( i = 0 ; i < stock ; i++)
                        printf("Entrer le titre du livre : \t");
                        scanf("%s", &title[stock]);
                        printf("Entrer l'auteur du livre : \t");
                        scanf("%s", &price[stock]);
                        printf("Entrer le prix du livre : \t");
                        scanf("%f", &price[stock]);
                        printf("Enrer la quantite du stock : \t");
                        scanf("%d", &quantity[stock]);
                        printf("Le livre a ete ajouter avec succes !.");
                break;
                case 2 : 
                    for ( i = 0 ; i < stock ; i++)
                    {
                        if (stock == 0)
                        {
                            printf("les livre est out of stock.");
                        }
                        else 
                        {
                        printf("\n\n-----------------Les livres disponible-----------------\n");
                        printf("le titre du livre %d est : \t %s", i + 1 , title[stock]);
                        printf("l'auteur du livre %d : \t %s", i + 1 , &auteur[stock]);
                        printf("le prix du livre %d : \t %.2f", i + 1 ,price[stock]);
                        printf("la quantite du stock %d :  \t%d", i + 1 ,quantity[stock]);
                        }
                    }
                    break;
            }
        }
        while(choice != 7);
return 0;
}