#include <stdio.h>
#include <stdlib.h>

void decToBin()
{
    int opt, i, dec, bin[32];

    do{
        system("cls");
        printf("=====================================\n");
        printf("|          Desimal --> Biner        |\n");
        printf("=====================================\n\n");

        printf("    Masukan bil. desimal : ");
        while (scanf("%d", &dec) == 0 || dec < 0)
        {
            printf("    Invalid input . . .\n\n");
            printf("    Masukan bil. desimal : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        for(i = 0; dec > 0; i++)
        {
            bin[i] = dec % 2;
            dec = dec / 2;
        }
        
        printf("    Konversi ke biner    : ");

        if(dec == 0)
            printf("0");
 
        for(i = i - 1; i >= 0; i--)
        {
            printf("%d", bin[i]);
        }

        printf("\n\n=====================================\n");
        printf("|     [1] Ulangi    [2] Kembali     |\n");
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
}

void binToDec()
{   
    int opt;
    do{
        int bin, dec = 0, base = 1, lastDigit;
        system("cls");
        printf("=====================================\n");
        printf("|         Biner --> Desimal         |\n");
        printf("=====================================\n\n");

        printf("    Masukan bil. biner  : ");
        while (scanf("%d", &bin) == 0 || bin < 0)
        {
            printf("    Invalid input . . .\n\n");
            printf("    Masukan bil. biner  : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        while(bin != 0)
        {
            lastDigit = bin % 10;
            dec = dec + lastDigit * base;
            bin = bin / 10;
            base = base * 2;
        }
        printf("    Konversi ke desimal : %d", dec);

        printf("\n\n=====================================\n");
        printf("|     [1] Ulangi    [2] Kembali     |\n");
        printf("=====================================\n");
        printf(">> ");
        while (scanf("%d", &opt) == 0 || opt < 1 || opt > 2)
        {
            printf("Invalid input . . .\n");
            printf("\n>> ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while (opt != 2);
}

void close()
{
    system("cls");
    printf("\n\t==============================");
    printf("\n\t|     Terimakasih telah      |");
    printf("\n\t|   menggunakan program ini  |");
    printf("\n\t==============================");
    printf("\n\n");
}

int main()
{
    int menu;
    do{
        system("cls");
        printf("=====================================\n");
        printf("|               KONVERSI            |\n");
        printf("=====================================\n");
        printf("|                                   |\n");
        printf("|       [1] Desimal ke biner        |\n");
        printf("|       [2] Biner ke desimal        |\n");
        printf("|                                   |\n");
        printf("|       [3] Keluar                  |\n");
        printf("|                                   |\n");
        printf("=====================================\n");
        printf("\n>> ");
        while (scanf("%d", &menu) == 0 || menu < 1 || menu > 3)
        {
            printf("Invalid input . . .\n");
            printf("\n>> ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if(menu == 1)
        decToBin();
        else if(menu == 2)
        binToDec();
    } while(menu != 3);
    close();

    return 0;
}