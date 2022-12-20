#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int minMov(int n)
{
    return pow(2, n) - 1;
}

void rekursif(int n, char start, char end, char middle)
{
    if (n == 1) 
    {
        printf("\n\t\t|  Pindahkan cakram 1 pada tiang %c ke tiang %c  |", start, end);
        return;
    }
    rekursif(n - 1, start, middle, end);
    printf("\n\t\t|  Pindahkan cakram %d pada tiang %c ke tiang %c  |", n, start, end);
    rekursif(n - 1, middle, end, start);
}

void iteratif(int cakram)
{
    for(int i = 1; i < (1 << cakram); i++)
    printf("\n\t\t|  Pindahkan cakram dari tiang %d ke tiang %d    |", (i & i - 1) % cakram + 1, ((i | i - 1) + 1) % cakram + 1);
}

int main()
{
    int opt, opt2, n;
    while(1) {
        system("cls");
        printf("\n\t\t================================================\n");
        printf("\t\t|                TOWER OF HANOI                |\n");
        printf("\t\t================================================\n");
        printf("\t\t|                                              |\n");
        printf("\t\t|     [1] Metode Rekursif                      |\n");
        printf("\t\t|     [2] Metode Iteratif                      |\n");
        printf("\t\t|                                              |\n");
        printf("\t\t|     [3] Keluar                               |\n");
        printf("\t\t|                                              |\n");
        printf("\t\t================================================\n\n");
        printf("\t\t>> ");
        while (scanf("%d", &opt) == 0 || opt < 1 || opt > 3)
        {
            printf("\t\tInvalid input . . .");
            printf("\n\n\t\t>> ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if (opt == 3) {
            break;
        }

        do{
            system("cls");
            int jml_cakram;

            if (opt == 1) {
                printf("\n\t\t================================================\n");
                printf("\t\t|                METODE REKURSIF               |\n");
                printf("\t\t================================================\n\n");
            }
            else if (opt == 2) {
                printf("\n\t\t================================================\n");
                printf("\t\t|                METODE ITERATIF               |\n");
                printf("\t\t================================================\n\n");
            }

            printf("\t\t     Masukan jumlah cakram : ");
            while (scanf("%d", &jml_cakram) == 0 || jml_cakram < 1)
            {
                printf("\t\t     Jumlah cakram harus > 0 . . .\n\n");
                printf("\t\t     Masukan jumlah cakram : ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            
            printf("\n\t\t================================================");
            printf("\n\t\t|                                              |");
            printf("\n\t\t|  Langkah penyelesaian :                      |");
            if (opt == 1)
                rekursif(jml_cakram, 'A', 'C', 'B');
            else if (opt == 2)
                iteratif(jml_cakram);
            printf("\n\t\t|  Selesai. . .                                |");
            printf("\n\t\t|                                              |");
            printf("\n\t\t================================================");
            printf("\n\n\t\t     Langkah minimum yang diperlukan : %d\n", minMov(jml_cakram));

            printf("\n\t\t================================================\n");
            printf("\t\t|          [1] Ulangi      [2] Kembali         |\n");
            printf("\t\t================================================\n\n");
            printf("\t\t>> ");
            while (scanf("%d", &opt2) == 0 || opt2 < 1 || opt2 > 2)
            {
                printf("\t\tInvalid input . . .\n");
                printf("\n\t\t>> ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        } while(opt2 != 2);
    };
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