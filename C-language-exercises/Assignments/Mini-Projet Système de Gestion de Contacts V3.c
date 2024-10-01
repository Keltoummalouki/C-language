#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contacts {
    int ID;
    char Nom[50];
    long NumTele;
    char Email[50];
};

struct contacts c1[100];
int Cont = 0;
int currentID = 1;

void RegenerateIDs() {
    for (int i = 0; i < Cont; i++) {
        c1[i].ID = i + 1;
    }
}

int VNP(long NumTele) {
    int length = 0;
    while (NumTele > 0) {
        NumTele /= 10;
        length++;
    }
    return (length == 9);
}

int VE(char *email) {
    return (strstr(email, "@gmail.com") != NULL);
}

void contactTest() {
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

    for (int i = 0; i < 10; i++) {
        c1[i].ID = currentID++;
        strcpy(c1[i].Nom, noms[i]);
        c1[i].NumTele = numeros[i];
        strcpy(c1[i].Email, emails[i]);
        Cont++;
    }
}

int contactExists(char *nom) {
    for (int i = 0; i < Cont; i++) {
        if (strcmp(c1[i].Nom, nom) == 0) {
            return 1;
        }
    }
    return 0;
}

void contact() {
    char nom[50];
    if (Cont < 100) {
        printf("\n\e[0;33m---------- Ajouter un contact ----------\e[0m\n");
        
        printf("\nEntrer le nom du contact : ");
        scanf("%s", nom);

        if (contactExists(nom)) {
            printf("\n\e[0;31mErreur : Le contact '%s' existe déjà.\e[0m\n", nom);
            return;
        }

        c1[Cont].ID = currentID++;
        strcpy(c1[Cont].Nom, nom);
        
        do {
            printf("\nEntrer le numero de telephone : +212 ");
            scanf("%ld", &c1[Cont].NumTele);
            if (!VNP(c1[Cont].NumTele)) {
                printf("\n\e[0;31mErreur : Le numero doit contenir 9 chiffres.\e[0m\n");
            }
        } while (!VNP(c1[Cont].NumTele));

        do {
            printf("\nEntrer l'Adresse e-mail : ");
            scanf("%s", c1[Cont].Email);
            if (!VE(c1[Cont].Email)) {
                printf("\n\e[0;31mErreur : L'email doit contenir @gmail.com.\e[0m\n");
            }
        } while (!VE(c1[Cont].Email));

        Cont++;
        printf("\n\e[0;32mLe contact a ete ajoute avec succes !\e[0m\n");
    } else {
        printf("\n\e[0;31mErreur : Limite de contacts atteinte.\e[0m\n");
    }
}

void Menu() {
    printf("\e[0;33m\n---------- Menu ----------\e[0m\n");
    printf("1. Ajouter un Contact\n");
    printf("2. Modifier un Contact\n");
    printf("3. Supprimer un Contact\n");
    printf("4. Afficher Tous les Contacts\n");
    printf("5. Rechercher un Contact\n");
    printf("6. Quitter\n");
}

void Aff() {
    if (Cont == 0) {
        printf("\n\e[0;31mIl n'y a aucun contact.\e[0m\n");
    } else {
        printf("-------------------------------------------------------------------\n");
        printf("| Nom          | Num de Telephone     | Email                     |\n");
        printf("-------------------------------------------------------------------\n");
        for (int i = 0; i < Cont; i++) {
            printf("| %-12s | +212 %9ld       | %-24s |\n", c1[i].Nom, c1[i].NumTele, c1[i].Email);
        }
        printf("-------------------------------------------------------------------\n");
    }
}

void Modifier() {
    char Mnv[50];
    int found = 0;

    printf("\nEntrer le nom du contact à modifier : ");
    scanf("%s", Mnv);

    for (int i = 0; i < Cont; i++) {
        if (strcmp(c1[i].Nom, Mnv) == 0) {
            printf("\n---------- Informations actuelles ----------\n");
            printf("Nom : %s\n", c1[i].Nom);
            printf("Numero de telephone : +212 %ld\n", c1[i].NumTele);
            printf("Adresse e-mail : %s\n", c1[i].Email);
            printf("\n---------- Modifier les informations ----------\n");

            do {
                printf("Entrer le nouveau numero de telephone : +212 ");
                scanf("%ld", &c1[i].NumTele);
                if (!VNP(c1[i].NumTele)) {
                    printf("\n\e[0;31mErreur : Le numero doit contenir 9 chiffres.\e[0m\n");
                }
            } while (!VNP(c1[i].NumTele));

            do {
                printf("\nEntrer l'Adresse e-mail : ");
                scanf("%s", c1[i].Email);
                if (!VE(c1[i].Email)) {
                    printf("\n\e[0;31mErreur : L'email doit contenir @gmail.com.\e[0m\n");
                }
            } while (!VE(c1[i].Email));

            printf("\n\e[0;32mLes informations du contact ont ete modifiees avec succes !\e[0m\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n\e[0;31mLe contact n'existe pas.\e[0m\n");
    }
}

void Supp() {
    char S[50];
    int found = 0;
    int C;

    printf("\nEntrer le nom du contact à supprimer : ");
    scanf("%s", S);

    for (int i = 0; i < Cont; i++) {
        if (strcmp(c1[i].Nom, S) == 0) {
            printf("\nEtes-vous sur de vouloir supprimer ce contact ?\n");
            printf("1. Oui\n");
            printf("2. Non\n");
            printf("Choisir (1/2) : ");
            scanf("%d", &C);

            if (C == 1) {
                for (int j = i; j < Cont - 1; j++) {
                    c1[j] = c1[j + 1]; 
                }
                Cont--;
                printf("\n\e[0;32mLe contact a ete supprime avec succes !\e[0m\n");
                found = 1;
                break;
            } else {
                return;
            }
        }
    }

    if (!found) {
        printf("\n\e[0;31mLe contact n'existe pas.\e[0m\n");
    }
}

void Rech() { 
    char rech[50];
    int found = 0; 

    printf("\nEntrer le nom du contact : ");
    scanf("%s", rech);

    for (int i = 0; i < Cont; i++) {
        if (strcmp(c1[i].Nom, rech) == 0) {
            printf("\n---------- Informations du contact ----------\n");
            printf("Nom : %s\n", c1[i].Nom);
            printf("Numero de telephone : +212 %ld\n", c1[i].NumTele);
            printf("Adresse e-mail : %s\n", c1[i].Email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n\e[0;31mLe contact n'existe pas.\e[0m\n");
    }
}

void Switch() {
    int choice = 0;

    while (choice != 6) {
        Menu();
        printf("\nEntrer votre choix : ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 6) {
            printf("\n\e[0;31mEntrer un choix valide.\e[0m\n");
            continue;
        }

        switch (choice) {
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
                printf("\n\e[0;32mMerci d'avoir utilise le programme. À bientot !\e[0m\n");
                exit(0);
        }
    }
}

int main() {
    contactTest();
    Switch();
    return 0;
}
