#include <stdio.h>

void close()
{
    system("cls");
    printf("\n\t==============================");
    printf("\n\t|                            |");
    printf("\n\t|     Terimakasih telah      |");
    printf("\n\t|   menggunakan program ini  |");
    printf("\n\t|                            |");
    printf("\n\t==============================");
    printf("\n\n");
}

int fib(int n) 
{   
    if(n == 0)
        return 0; 
    else if(n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

void rekursif(int n)
{
    printf("\nFIBONACCI REKURSIF : ");
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", fib(i));
    }
}

void iteratif(int n)
{
    int a = 0, b = 1, fib;

    printf("\nFIBONACCI ITERATIF : ");
    for(int i = 2; i < n; i++)
    {
        if(i == 2)
            printf("%d %d ", a, b);

        fib = a + b;
        printf("%d ", fib);

        a = b;
        b = fib;
    }
}

int main()
{
    int opt, n;
    do{
        system("cls");
        printf("=====================================\n");
        printf("|           DERET FIBONACCI         |\n");
        printf("=====================================\n\n");
        printf("     Masukan panjang deret : ");
        while (scanf("%d", &n) == 0 || n < 3)
        {
            printf("   # Panjang deret minimal adalah 3 . . .\n\n");
            printf("     Masukan panjang deret : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        rekursif(n);
        printf("\n");
        iteratif(n);
        printf("\n\n=====================================\n");
        printf("|     [1] Ulangi     [2] Keluar     |\n");
        printf("=====================================\n");
        printf(">> ");
        while (scanf("%d", &opt) == 0 || opt < 1 || opt > 2)
        {
            printf("Invalid input . . .\n");
            printf("\n>> ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while(opt != 2);
    close();

    return 0;
}