#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float rumusAngsuranPokok(float p, int t)
{
    return p / t;
}

float rumusBungaKeY(float y, float p, float angsuranPokok, float i)
{
    return ((((p - ((y - 1) * angsuranPokok))) * i) / 12) / 100;
}

int main ()
{
    int opt; 
    int t; //lama pinjaman dalam bulan
    float 
    p, //pokok pinjaman
    i, //besar bunga dalam setahun
    y; //bunga bulan ke y

    system("cls");
    printf("\n\t===========================================================================================\n");
    printf("\t|                                 PROGRAM BUNGA & ANGSURAN                                |\n");
    printf("\t===========================================================================================\n\n");

    printf("\t\tMasukan pokok pinjaman                 : ");
    while (scanf("%f", &p) == 0 || p <= 0)
    {
        printf("\t      # Invalid input. . .\n\n");
        printf("\t\tMasukan pokok pinjaman                 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\t\tMasukan besar bunga dalam setahun (%%)  : ");
    while (scanf("%f", &i) == 0 || i <= 0)
    {
        printf("\t      # Invalid input. . .\n\n");
        printf("\t\tMasukan besar bunga dalam setahun (%%)  : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\t\tMasukan lama pinjaman (bulan)          : ");
    while (scanf("%d", &t) == 0 || t <= 0)
    {
        printf("\t      # Invalid input. . .\n\n");
        printf("\t\tMasukan lama pinjaman (bulan)          : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n\t===========================================================================================\n");

    float angsuranPokok = rumusAngsuranPokok(p, t);
    float bungaKeY = rumusBungaKeY(y, p, angsuranPokok, i);
    float angsuranPerbulan = angsuranPokok + bungaKeY;
    float totalBunga, totalAngsuran;

    printf("\n\tBulan\t\tBunga\t\t\tAngsuran Pokok\t\tAngsuran Perbulan\n");
    for(y = 1; y <= t; y++)
    {
        bungaKeY = rumusBungaKeY(y, p, angsuranPokok, i);
        totalBunga += bungaKeY;
        angsuranPerbulan = angsuranPokok + bungaKeY;
        totalAngsuran += angsuranPerbulan;

        printf("\t %.0f\t\t Rp. %.0f \t\t Rp. %.0f \t\t Rp. %.0f\n", y, floor(bungaKeY), floor(angsuranPokok), floor(angsuranPerbulan));
    }
    
    printf("\n\t===========================================================================================\n");
    printf("\n\t\tTotal Bunga\t\t\t\t\t\t Rp. %.0f", floor(totalBunga));
    printf("\n\t\tTotal Angsuran\t\t\t\t\t\t Rp. %.0f\n", floor(totalAngsuran));
    printf("\n\t===========================================================================================");
    printf("\n\t|                               [1] Ulangi          [2] Keluar                            |");
    printf("\n\t===========================================================================================");
    printf("\n\n\t>> ");
    while (scanf("%d", &opt) == 0 || opt < 1 || opt > 2)
    {
        printf("\tInvalid input . . .\n");
        printf("\n\t>> ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if(opt == 1)
        main();

    close();

    return 0;
}

void close()
{
    system("cls");
    printf("\n\t\t================================================\n");
    printf("\t\t|                                              |\n");
    printf("\t\t|               Terimakasih telah              |\n");
    printf("\t\t|            menggunakan program ini           |\n");
    printf("\t\t|                                              |\n");
    printf("\t\t================================================\n\n");
    printf("\n\n");
}