    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct contacts // structure contacts
    {
        int ID;
        char Nom[50];
        int NumTele;
        char Email[50];
    };

    struct contacts c1[100];
    int Cont = 0;
    int currentID = 1;


    void RegenerateIDs() // Auto generate ID
    {
        for (int i = 0; i < Cont; i++) 
        {
            c1[i].ID = i + 1;
        }
    }
    
    int VNP(int NumTele) // Validation number phone
    {
        int length = 0;
        while (NumTele > 0) 
        {
            NumTele /= 10;
            length++;
        }
        return (length == 9);
    }

    int VE(char *email) // Validation email
    {
        return (strstr(email, "@gmail.com") != NULL);
    }
    void contactTest()
    {
        const char *noms[] = {
            "Keltoum", "Marwa", "Salma", "Aya", "Zinb",
            "Sara", "Anass", "Othmane", "Mohamed", "Ali"
        };
        long numeros[] = {
            623456789, 623456789, 687654321, 611111111,
            622222222, 633333333, 663333333, 633233333,
            633322333, 633353339
        };
        const char *emails[] = {
            "Keltoumma@gmail.com", "Marwa@gmail.com", "Salma@gmail.com",
            "Aya@gmail.com", "Zinb@gmail.com", "Sara@gmail.com",
            "Anass@gmail.com", "Othmane@gmail.com", "Mohamed@gmail.com",
            "Ali@gmail.com"
        };

        for (int i = 0; i < 10; i++)
        {
            c1[i].ID = currentID++;
            strcpy(c1[i].Nom, noms[i]);
            c1[i].NumTele = numeros[i];
            strcpy(c1[i].Email, emails[i]);
            Cont++;
        }
    }
    int contactExists(char *nom)
    {
        for (int i = 0; i < Cont; i++)
        {
            if (strcmp(c1[i].Nom, nom) == 0)
            {
                return 1;
            }
        }
        return 0;
    }

    void contact() // Ajouter un contact
    {
        if (Cont < 100) 
        {
            c1[Cont].ID = currentID++;
            printf("\e[0;33m\n---------- Ajouter un contact ----------\e[0m\n");
            
            printf("\nEntrer le nom du contact : ");
            scanf("%s", c1[Cont].Nom);
            
            do 
            {
                printf("\nEntrer le numero de telephone : +212 ");
                scanf("%d", &c1[Cont].NumTele);
                if (!VNP(c1[Cont].NumTele)) 
                {
                    printf("\e[1;31m\nErreur : Le numero doit contenir 9 chiffres.\e[0m\n");
                }
            } while (!VNP(c1[Cont].NumTele));

            do 
            {
                printf("\nEntrer l'Adresse e-mail : ");
                scanf("%s", c1[Cont].Email);
                if (!VE(c1[Cont].Email))
                {
                    printf("\e[1;31m\nErreur : L'email doit contenir @gmail.com.\e[0m\n");
                }
            } while (!VE(c1[Cont].Email));

            Cont++;
            printf("\e[1;32m\nLe contact a ete ajoute avec succes !\e[0m\n\n");
        } 
        else 
        {
            printf("\e[1;31m\nErreur : Limite de contacts atteinte.\e[0m\n");
        }
    }

    void Menu() // Menu
    {
        printf("\e[0;33m\n\n---------- Menu ----------\n");
        printf("1. Ajouter un Contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un Contact\n");
        printf("4. Afficher Tous les Contacts\n");
        printf("5. Rechercher un Contact\n");
        printf("6. Quitter\e[0m\n");
    }

    void Modifier() // Modifier un contact
    {
        char Mnv[50];
        int found = 0;

        printf("\nEntrer le nom du contact a modifier : ");
        scanf("%s", Mnv);

        for (int i = 0; i < Cont; i++) 
        {
            if (strcmp(c1[i].Nom, Mnv) == 0) 
            {
                printf("\e[0;33m\n---------- Informations actuelles ----------\e[0m\n");
                printf("Nom : %s\n", c1[i].Nom);
                printf("Numero de telephone : +212 %d\n", c1[i].NumTele);
                printf("Adresse e-mail : %s\n", c1[i].Email);
                printf("\e[1;32m\n---------- Modifier les informations ----------\e[0m\n");

                printf("Entrer le nouveau numero de telephone : +212 ");
                scanf("%d", &c1[i].NumTele);
                while (!VNP(c1[i].NumTele)) 
                {
                    printf("\e[1;31m\nErreur : Le numero doit contenir 9 chiffres.\e[0m\n");
                    printf("Entrer le nouveau numero de telephone : +212 ");
                    scanf("%d", &c1[i].NumTele);
                }

                do 
                {
                    printf("\nEntrer l'Adresse e-mail : ");
                    scanf("%s", c1[i].Email);
                    if (!VE(c1[i].Email))
                    {
                        printf("\e[1;31m\nErreur : L'email doit contenir @gmail.com.\e[0m\n");
                    }
                } while (!VE(c1[i].Email));
                
                printf("\e[1;32m\nLes informations du contact ont ete modifiees avec succes !\e[0m\n");
                found = 1;
                break; 
            }
        }

        if (!found) 
        {
            printf("\e[1;31m\nLe contact n'existe pas.\e[0m\n");
        }
    }

    void Supp() // Supprimer un contact
    {
        char S[50];
        int found = 0;
        int C;

        printf("\nEntrer le nom du contact à supprimer : ");
        scanf("%s", S);

        for (int i = 0; i < Cont; i++) 
        {
            if (strcmp(c1[i].Nom, S) == 0) 
            {
                printf("\n\nEtes-vous sur de vouloir supprimer ce contact ?");
                printf("\n1. Oui");
                printf("\n2. Non\n");
                printf("Choisir (1/2) : ");
                scanf("%d", &C);

                if (C == 1) 
                {
                    for (int j = i; j < Cont - 1; j++) 
                    {
                        c1[j] = c1[j + 1]; 
                    }
                    Cont--;
                    printf("\e[1;32m\nLe contact a ete supprime avec succes !\e[0m\n");
                    found = 1;
                    break;
                } 
                else 
                {
                    return;
                }
            }
        }

        if (!found) 
        {
            printf("\e[1;31m\nLe contact n'existe pas.\e[0m\n");
        }
    }

void Aff()
{
    if (Cont == 0)
    {
        printf("\n\033[1;31mIl n'y a aucun contact.\033[0m\n");
    }
    else
    {
        printf("------------------------------------------------------------------------\n");
        printf("| \033[1;34mID\033[0m | \033[1;34mNom          \033[0m | \033[1;34mNum de Telephone \033[0m | \033[1;34mEmail                     \033[0m |\n");
        printf("------------------------------------------------------------------------\n");
        for (int i = 0; i < Cont; i++)
        {
            printf("| \033[1;33m%2d\033[0m | \033[1;33m%-12s\033[0m | \033[1;33m+212 %9ld       \033[0m | \033[1;33m%-24s\033[0m |\n", c1[i].ID, c1[i].Nom, c1[i].NumTele, c1[i].Email);
        }
        printf("------------------------------------------------------------------------\n");
    }
    }

    void Rech() // Rechercher un contact
    { 
        char rech[50];
        int found = 0; 

        printf("\nEntrer le nom du contact : ");
        scanf("%s", rech);

        for (int i = 0; i < Cont; i++) 
        {
            if (strcmp(c1[i].Nom, rech) == 0) 
            {
                printf("\e[0;33m\n---------- Informations du contact ----------\e[0m\n");
                printf("Nom : %s\n", c1[i].Nom);
                printf("Numero de telephone : +212 %d\n", c1[i].NumTele);
                printf("Adresse e-mail : %s\n", c1[i].Email);
                found = 1;
                break;
            }
        }

        if (!found) 
        {
            printf("\e[1;31m\nLe contact n'existe pas.\e[0m\n");
        }
    }

    void Switch() 
    {
        int choice = 0;

        while (choice != 6) 
        {
            Menu();
            printf("\nEntrer votre choix : ");
            scanf("%d", &choice);
            
            if (choice < 1 || choice > 6) 
            {
                printf("\e[1;31m\nEntrer un choix valide.\e[0m\n");
                continue;
            }

            switch (choice) 
            {
                case 1:
                    contact();
                    break;
                case 2:
                    Modifier();
                    break;
                case 3:
                    Supp();
                    break;
                case 4:
                    Aff();
                    break;
                case 5:
                    Rech();
                    break;
                case 6:
                    printf("\e[1;32m\nMerci d'avoir utilise le programme. À bientot !\e[0m\n\n");
                    exit(0);
                    break;
            }
        }
    }

    int main() 
    {
        Switch();
        return 0;
    }
