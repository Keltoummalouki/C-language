#include <stdio.h>
#include <string.h>

int main()
{
    double price[100];
    char title[100][50];
    char auteur[100][50];
    char a[50];
    int quantity[100];
    int stock = 0;
    int TotalQuantity = 0;
    int choice;
    int i, n;
    int NvQ;
    char Supp[50];
    int found;

    do
    {
        printf("\n\n-----------------Menu-----------------\n");
        printf("1 - Ajouter un livre au stock.\n");
        printf("2 - Afficher les livres disponibles.\n");
        printf("3 - Chercher un livre par son titre.\n");
        printf("4 - Mise a jour des informations d'un livre.\n");
        printf("5 - Supprimer un livre.\n");
        printf("6 - Calculer le stock des livres disponibles.\n");
        printf("7 - Quitter\n");
        printf("Saisissez votre choix : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEntrer le titre du livre : \t");
                scanf("%s", title[stock]);
                printf("Entrer l'auteur du livre : \t");
                scanf("%s", auteur[stock]);
                printf("Entrer le prix du livre : \t");
                scanf("%lf", &price[stock]);
                printf("Entrer la quantite du stock : \t");
                scanf("%d", &quantity[stock]);
                printf("Le livre a ete ajoute avec succes !");
                stock++;
                break;

            case 2:
                if (stock == 0)
                {
                    printf("\nAucun livre disponible.");
                }
                else
                {
                    printf("\n\n-----------------Les livres disponibles-----------------\n");
                    for (i = 0; i < stock; i++)
                    {
                        printf("\nTitre du livre %d: %s", i + 1, title[i]);
                        printf("\nAuteur du livre %d: %s", i + 1, auteur[i]);
                        printf("\nPrix du livre %d: %.2f $", i + 1, price[i]);
                        printf("\nQuantite en stock %d: %d", i + 1, quantity[i]);
                    }
                }
                break;

            case 3:
                printf("\nEntrer le titre du livre : \t");
                scanf("%s", a);
                found = 0;
                for (i = 0; i < stock; i++)
                {
                    if (strcmp(title[i], a) == 0)
                    {
                        printf("\n\n-----------------Livre trouve-----------------\n");
                        printf("\nTitre: %s", title[i]);
                        printf("\nAuteur: %s", auteur[i]);
                        printf("\nPrix: %.2f $", price[i]);
                        printf("\nQuantite en stock: %d", quantity[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("\nLivre non trouve!");
                }
                break;

            case 4:
                printf("Entrer le titre du livre à mettre à jour: ");
                scanf("%s", a);
                found = 0;
                for (i = 0; i < stock; i++)
                {
                    if (strcmp(title[i], a) == 0)
                    {
                        printf("Entrez la nouvelle quantite: ");
                        scanf("%d", &NvQ);
                        quantity[i] = NvQ;
                        printf("Quantite mise a jour avec succes.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("\nLivre non trouve!");
                }
                break;

            case 5:
                printf("Entrer le titre du livre a supprimer: ");
                scanf("%s", Supp);
                found = 0;
                for (i = 0; i < stock; i++)
                {
                    if (strcmp(title[i], Supp) == 0)
                    {
                        for (int j = i; j < stock - 1; j++)
                        {
                            strcpy(title[j], title[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            price[j] = price[j + 1];
                            quantity[j] = quantity[j + 1];
                        }
                        stock--;
                        printf("Livre supprime avec succes.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("\nLivre non trouve!");
                }
                break;

            case 6:
                TotalQuantity = 0;
                for (i = 0; i < stock; i++)
                {
                    TotalQuantity += quantity[i];
                }
                printf("Le nombre total de livres en stock est : %d\n", TotalQuantity);
                break;
        }
    } while (choice != 7);

    return 0;
}
