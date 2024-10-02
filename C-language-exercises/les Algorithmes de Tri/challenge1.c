#include <stdio.h>
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define Rest "\e[0m"
void Espace()
{
    printf("\n");
}

    void swap(int *a, int *b) 
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void Selection(int Arr[], int n)
    {
       for ( int i = 0 ; i < n ; i++)
       {
        printf("%d " , Arr[i]);
       }
       Espace();
    }
    void TriSelection(int Arr[] , int n)
    {
        for ( int i = 0 ; i < n - 1 ; i++)
        {
            int Index = i ;
            for ( int j = i + 1 ; j < n ; j++)
            {
                if ( Arr[j] < Arr[Index])
                Index = j;
            }
            swap(&Arr[Index], &Arr[i]);
        }
    }

    int main()
    {
         
        int Arr[] = { 12, 23 , 77 , 231 , 999 , 1 };
        int n = sizeof(Arr)/sizeof(Arr[0]);

        printf(BRED"\nLe Tableau avant le Tri : \t"Rest);
        Selection(Arr , n);
        TriSelection(Arr , n);
        printf(BGRN"Le tableau apres le Tri par selection : \t"Rest);
        Selection(Arr , n);
        Espace();

        return 0;
    }