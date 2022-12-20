#include <stdio.h>  
#include <math.h>
#include <stdlib.h>

void ulang()
{
    int pilihan;
    getch();
    printf("\t[1] Ulangi\n");
    printf("\t[2] Keluar\n");
    printf("\t==============================\n");
    printf("\t>> ");
    while (scanf("%d", &pilihan) == 0 || pilihan < 1 || pilihan > 2)
    {
        printf("\n\tInvalid input . . .");
        printf("\n\t>> ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    switch (pilihan)
    {
        case 1:
            main();
            break;
        case 2:
            keluar();
            break;
    }
}

void penjumlahan()
{
    double num1, num2, hasil;
    system("cls");
    printf("\n");
    printf("\t==============================\n");
    printf("\t         PENJUMLAHAN          \n");
    printf("\t==============================\n");

    printf("\tMasukan angka pertama : ");
    while (scanf("%lf", &num1) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka pertama : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan angka kedua   : ");
    while (scanf("%lf", &num2) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka kedua : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    hasil = num1 + num2;
    printf("\n\tHasil : %.2lf", hasil);
    printf("\n\t==============================\n");
}

void pengurangan()
{
    double num1, num2, hasil;
    system("cls");
    printf("\n");
    printf("\t==============================\n");
    printf("\t          PENGURANGAN         \n");
    printf("\t==============================\n");

    printf("\tMasukan angka pertama : ");
    while (scanf("%lf", &num1) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka pertama : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan angka kedua   : ");
    while (scanf("%lf", &num2) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka kedua : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    hasil = num1 - num2;
    printf("\n\tHasil : %.2lf", hasil);
    printf("\n\t==============================\n");
}

void perkalian()
{
    double num1, num2, hasil;
    system("cls");
    printf("\n");
    printf("\t==============================\n");
    printf("\t           PERKALIAN          \n");
    printf("\t==============================\n");

    printf("\tMasukan angka pertama : ");
    while (scanf("%lf", &num1) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka pertama : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan angka kedua   : ");
    while (scanf("%lf", &num2) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka kedua : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    hasil = num1 * num2;
    printf("\n\tHasil : %.2lf", hasil);
    printf("\n\t==============================\n");   
}

void pembagian()
{
    double num1, num2, hasil;
    system("cls");
    printf("\n");
    printf("\t==============================\n");
    printf("\t           PEMBAGIAN          \n");
    printf("\t==============================\n");

    printf("\tMasukan angka pertama : ");
    while (scanf("%lf", &num1) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka pertama : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan angka kedua   : ");
    while (scanf("%lf", &num2) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka kedua : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    hasil = num1 / num2;
    printf("\n\tHasil : %.2lf", hasil);
    printf("\n\t==============================\n");
}

void modulus()
{
    double num1, num2, hasil;
    system("cls");
    printf("\n");
    printf("\t==============================\n");
    printf("\t            MODULUS           \n");
    printf("\t==============================\n");

    printf("\tMasukan angka pertama : ");
    while (scanf("%lf", &num1) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka pertama : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan angka kedua   : ");
    while (scanf("%lf", &num2) == 0)
    {
        printf("\n\tMasukan angka dengan benar . . .\n");
        printf("\n\tMasukan angka kedua : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    hasil = fmod(num1, num2);
    printf("\n\tHasil : %.2lf", hasil);
    printf("\n\t==============================\n"); 
}

void keluar()
{
    system("cls");
    printf("\n\t==============================");
    printf("\n\t      Terimakasih telah       ");
    printf("\n\t    menggunakan program ini   ");
    printf("\n\t==============================");
    printf("\n\tProgram telah dihentikan . . .\n\n\n");
    exit(0);
}

int main()
{
    int menu;
    system("cls");
    printf("\n");
    printf("\t==============================\n");
    printf("\t       BASIC CALCULATOR       \n");
    printf("\t==============================\n");
    printf("\t[1] Penjumlahan\n");
    printf("\t[2] Pengurangan\n");
    printf("\t[3] Perkalian\n");
    printf("\t[4] Pembagian\n");
    printf("\t[5] Modulus\n");
    printf("\t==============================");
    printf("\n\t>> ");
    while (scanf("%d", &menu) == 0 || menu < 1 || menu > 5)
    {
        printf("\n\tInvalid input . . .");
        printf("\n\t>> ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    switch(menu)
    {
        case 1:
            penjumlahan();
            break;
        case 2:
            pengurangan();
            break;
        case 3:
            perkalian();
            break;
        case 4:
            pembagian();
            break;
        case 5:
            modulus();
            break;
    }
    ulang();
    return 0;
}
