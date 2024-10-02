    #include <stdio.h>
    #include <string.h>
    //color codes
    #define BBLK "\e[1;30m"
    #define BRED "\e[1;31m"
    #define BGRN "\e[1;32m"
    #define BYEL "\e[1;33m"
    #define BBLU "\e[1;34m"
    #define BMAG "\e[1;35m"
    #define BCYN "\e[1;36m"
    #define BWHT "\e[1;37m"
    #define Rest "\e[0m"

    #define MAX_RESERVATIONS 100 //Nombre max des reservation

    struct Reservation 
    {
        int ID;
        char LastName[100];
        char FirstName[100];
        long PhoneNumber;
        int Age;
        char Statut[20];
        int Day;
        int Month;
        int Year;
    };


    struct Reservation reservations[MAX_RESERVATIONS];
    int RSC = 0; // RSC : reservation Count
    int currentID = 1;
    
    void TestData() //generate Default Data
    {
        const char *firstNames[] = {"Keltoum", "Marwa", "Salma", "Aya", "Zinb", "Sara", "Anass", "Othmane", "Mohamed", "Ali"};
        const char *lastNames[] = {"Bensalem", "ElMouradi", "Fekhar", "Tazi", "Ouazzani", "Benzakour", "Alaoui", "El Yousfi", "Belkadi", "El Idrissi"};
        long phoneNumbers[] = {623456789, 623456788, 687654321, 611111111, 622222222, 633333333, 663333333, 633233333, 633322333, 633353339};
        int ages[] = {18, 9, 15, 20, 54, 43, 22, 15, 18, 12};
        const char *statuts[] = {"valide", "reporte", "annule", "traite", "valide", "annule", "valide", "reporte", "traite", "valide"};
        int days[] = {12, 1, 7, 27, 18, 3, 2, 10, 20, 15};
        int months[] = {12, 1, 7, 2, 8, 3, 2, 10, 4, 5};
        int years[] = {2024, 2024, 2024, 2024, 2024, 2024, 2024, 2024, 2024, 2024};

        for (int i = 0; i < 10; i++) 
        {
            reservations[i].ID = currentID++;
            strcpy(reservations[i].FirstName, firstNames[i]);
            strcpy(reservations[i].LastName, lastNames[i]);
            reservations[i].PhoneNumber = phoneNumbers[i];
            reservations[i].Age = ages[i];
            strcpy(reservations[i].Statut, statuts[i]);
            reservations[i].Day = days[i];
            reservations[i].Month = months[i];
            reservations[i].Year = years[i];
            RSC++; // RSC : reservation Count
        }
    }

    void add() //add Reservation
    {
        if (RSC < MAX_RESERVATIONS) 
        {
            struct Reservation new; // new : new Reservation
            new.ID = currentID++;

            printf("Entrer le prenom : ");
            scanf("%s", new.FirstName);
            printf("Entrer le nom : ");
            scanf("%s", new.LastName);
            printf("Entrer le numero de telephone : +212 ");
            scanf("%ld", &new.PhoneNumber);
            printf("Entrer l'age : ");
            scanf("%d", &new.Age);
            printf("Entrer le statut (valide, reporte, annule, traite) : ");
            scanf("%s", new.Statut);
            printf("Entrer le jour de reservation : ");
            scanf("%d", &new.Day);
            printf("Entrer le mois de reservation : ");
            scanf("%d", &new.Month);
            printf("Entrer l'annee de reservation : ");
            scanf("%d", &new.Year);

            reservations[RSC++] = new; // RSC : reservation Count // new : new Reservation
            printf(BGRN "La reservation a ete ajoutee avec succes!\n" Rest);
        } 
        else 
        {
            printf(BRED "Erreur : Nombre maximal de reservations atteint.\n" Rest);
        }
    }

    void modify() //modify Reservation
    {
        int id;
        printf("Entrez l'ID de la reservation a modifier : ");
        scanf("%d", &id);

        for (int i = 0; i < RSC; i++) 
        {
            if (reservations[i].ID == id) 
            {
                printf("Entrez le nouveau prenom : ");
                scanf("%s", reservations[i].FirstName);
                printf("Entrez le nouveau nom : ");
                scanf("%s", reservations[i].LastName);
                printf("Entrez le nouveau numero de telephone : +212 ");
                scanf("%ld", &reservations[i].PhoneNumber);
                printf("Entrez le nouvel age : ");
                scanf("%d", &reservations[i].Age);
                printf("Entrez le nouveau statut (valide, reporte, annule, traite) : ");
                scanf("%s", reservations[i].Statut);
                printf("Entrez la nouvelle date de reservation (jour mois annee) : ");
                scanf("%d %d %d", &reservations[i].Day, &reservations[i].Month, &reservations[i].Year);
                printf(BGRN "Les informations de la reservation ont ete modifiees avec succes!\n" Rest);
                return;
            }
        }
        printf(BRED "Erreur : La reservation avec l'ID %d n'a pas ete trouvee.\n" Rest, id);
    }

    void delete() //delete Reservation
    {
        int id;
        printf("Entrez l'ID de la reservation a supprimer : ");
        scanf("%d", &id);

        for (int i = 0; i < RSC; i++) 
        {
            if (reservations[i].ID == id) 
            {
                for (int j = i; j < RSC - 1; j++) 
                {
                    reservations[j] = reservations[j + 1];
                }
                RSC--;
                printf(BGRN "La reservation a ete supprimee avec succes!\n" Rest);
                return;
            }
        }
        printf(BRED "Erreur : La reservation avec l'ID %d n'a pas ete trouvee.\n" Rest, id);
    }

    void display() //display Reservations
    {
        if (RSC == 0) 
        {
            printf(BRED "Aucune reservation n'a ete trouvee.\n" Rest);
        } 
        else 
        {
            printf("-----------------------------------------------------------------------------------------\n");
            printf("| ID\t| Nom\t        | Prenom\t| Telephone\t        | Age\t | Statut\t|\n");
            printf("-----------------------------------------------------------------------------------------\n");
            for (int i = 0; i < RSC; i++) 
            {
            printf("| %-2d\t| %-8s\t| %-8s\t| +212 %-9ld\t| %-3d\t| %-8s\t|\n",
                    reservations[i].ID,
                    reservations[i].LastName,
                    reservations[i].FirstName,
                    reservations[i].PhoneNumber,
                    reservations[i].Age,
                    reservations[i].Statut);
            }
            printf("-----------------------------------------------------------------------------------------\n");
        }
    }

    void menu() {
        int choice;

        do 
        {
            printf("\n1. Ajouter une reservation\n");
            printf("2. Modifier une reservation\n");
            printf("3. Supprimer une reservation\n");
            printf("4. Afficher toutes les reservations\n");
            printf("5. Quitter\n");
            printf("Entrez votre choix : ");
            scanf("%d", &choice);

            switch (choice) 
            {
                case 1:
                    add();
                    break;
                case 2:
                    modify();
                    break;
                case 3:
                    delete();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    printf(BGRN "Merci d'avoir utilise le programme. A bientot!\n" Rest);
                    break;
                default:
                    printf(BRED "Erreur : Choix invalide.\n" Rest);
                    break;
            }
        } while (choice != 5);
    }

    int main() 
    {
        TestData();
        menu();
        return 0;
    }
