#include <stdio.h>
#include <stdlib.h>

    struct contacts
    {
        char  Nom[50];
        int NumTele[50];
        char Email[50];
    };

    void contact()
    {
        struct  contacts c1;
        c1.Nom[50];
        c1.NumTele[50];
        c1.Email[50];
        printf("\e[0;33m\n----------Ajouter un contact----------\e[0m\n");
        printf("\nEntrer le nom du contact : ");
        scanf("%s" , &c1.Nom);
        printf("\nEntrer le numero de telephone : ");
        scanf("%d" , &c1.NumTele);
        printf("\nEntrer l'Adresse e-mail : ");
        scanf("%s" , &c1.Email);
    }

    int Menu()
    {
                printf("\e[0;33m----------Menu----------\n");
                printf("1. Ajouter un Contact\n");
                printf("2. Modifier un Contact\n");
                printf("3. Supprimer un Contact\n");
                printf("4. Afficher Tous les Contacts\n");
                printf("5. Rechercher un Contact\n");
                printf("6. Quitter\e[0m\n");
    }
    int Modif()
    {
        char a[50];
        printf("Entrer le nom du contact  a modifier : ");
        scanf("%s" , &a)
        

    }

        int choix()
        {
            int choice;
                printf("Entrer  votre choix : ");
                scanf("%d" ,  &choice);
                if (choice < 1 || choice > 6)
                {
                printf("\e[1;31mEntrer  un choix valide\n \e[0m");
                Menu();
                }
            switch(choice)
            {
            case 1 :
            contact();
            printf("\e[1;32m Le contact ete ajoute avec succes!.\e[0m");

            }
        }

    
    int main()
    {
        Menu();
        choix();

        return 0;
    }