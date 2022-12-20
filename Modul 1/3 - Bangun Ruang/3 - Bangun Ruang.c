#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PHI 3.14

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

double volume_tabung(double r, double tinggi)
{
    return PHI * r * r * tinggi;
}

double lp_tabung(double r, double tinggi)
{
    return PHI * r * (r + tinggi);
}

void tabung()
{
    double r, tinggi, volume, lp;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t            TABUNG            ");
    printf("\n\t==============================\n");

    printf("\tMasukan jari-jari : ");
    while (scanf("%lf", &r) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan jari-jari : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi    : ");
    while (scanf("%lf", &tinggi) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi    : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    volume = volume_tabung(r, tinggi);
    lp = lp_tabung(r, tinggi);

    printf("\n\tVOLUME         : %.2lf\n", volume);
    printf("\tLUAS PERMUKAAN : %.2lf", lp);
    printf("\n\t==============================\n");
}

double volume_bola(double r)
{
    return 1.33333 * PHI * r * r * r;
}

double lp_bola(double r)
{
    return 4 * PHI * r * r;
}

void bola()
{
    double r, volume, lp;
     
    system("cls");
    printf("\n\t==============================");
    printf("\n\t              BOLA            ");
    printf("\n\t==============================\n");

    printf("\tMasukan jari-jari : ");
    while (scanf("%lf", &r) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan jari-jari : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    volume = volume_bola(r);
    lp = lp_bola(r);

    printf("\n\tVOLUME         : %.2lf", volume);
    printf("\n\tLUAS PERMUKAAN : %.2lf", lp);
    printf("\n\t==============================\n");
}

double volume_limas_segiempat(double panjang_alas, double tinggi)
{
    return 0.33333 * (panjang_alas * panjang_alas) * tinggi;
}

double lp_limas_segiempat(double panjang_alas, double tinggi)
{
    return (4 * (0.5 * panjang_alas * (sqrt(((0.5 * panjang_alas) * (0.5 * panjang_alas)) + (tinggi * tinggi))))) + (panjang_alas * panjang_alas);
}

void limas_segiempat()
{
    double panjang_alas, tinggi, volume, lp;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t        LIMAS SEGIEMPAT       ");
    printf("\n\t==============================\n");

    printf("\tMasukan panjang alas : ");
    while (scanf("%lf", &panjang_alas) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan luas alas : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi       : ");
    while (scanf("%lf", &tinggi) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    volume = volume_limas_segiempat(panjang_alas, tinggi);
    lp = lp_limas_segiempat(panjang_alas, tinggi);

    printf("\n\tVOLUME         : %.2lf", volume);
    printf("\n\tLUAS PERMUKAAN : %.2lf", lp);
    printf("\n\t==============================\n");
}

double volume_prisma_segitiga(double alas_segitiga, double tinggi_segitiga, double tinggi_prisma)
{
    return (0.5 * alas_segitiga * tinggi_segitiga) * tinggi_prisma;
}

double lp_prisma_segitiga(double alas_segitiga, double tinggi_segitiga, double tinggi_prisma)
{
    return (2 * alas_segitiga * tinggi_segitiga) + (3 * alas_segitiga * tinggi_prisma);
}

void prisma_segitiga()
{
    double alas_segitiga, tinggi_segitiga, tinggi_prisma, volume, lp;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t        PRISMA SEGITIGA       ");
    printf("\n\t==============================\n");

    printf("\tMasukan panjang alas segitiga : ");
    while (scanf("%lf", &alas_segitiga) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan panjang alas segitiga : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi segitiga : ");
    while (scanf("%lf", &tinggi_segitiga) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi segitiga : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi prisma   : ");
    while (scanf("%lf", &tinggi_prisma) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi prisma   : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    volume = volume_prisma_segitiga(alas_segitiga, tinggi_segitiga, tinggi_prisma);
    lp = lp_prisma_segitiga(alas_segitiga, tinggi_segitiga, tinggi_prisma);

    printf("\n\tVOLUME         : %.2lf", volume);
    printf("\n\tLUAS PERMUKAAN : %.2lf", lp);
    printf("\n\t==============================\n");    
}

double volume_kerucut(double r, double tinggi)
{
    return 0.33333 * (PHI * r * r) * tinggi;
}

double lp_kerucut(double r, double garis_peluncur)
{
    return PHI * r * (garis_peluncur + r);
}

void kerucut()
{
    double r, tinggi, garis_peluncur, volume, lp;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t            KERUCUT           ");
    printf("\n\t==============================\n");

    printf("\tMasukan jari-jari : ");
    while (scanf("%lf", &r) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan jari-jari : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi    : ");
    while (scanf("%lf", &tinggi) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi    : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan panjang garis peluncur : ");
    while (scanf("%lf", &garis_peluncur) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan panjang garis peluncur : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    volume = volume_kerucut(r, tinggi);
    lp = lp_kerucut(r, garis_peluncur);

    printf("\n\tVOLUME         : %.2lf", volume);
    printf("\n\tLUAS PERMUKAAN : %.2lf", lp);
    printf("\n\t==============================\n");
}

void keluar()
{
    system("cls");
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
    printf("\n\t==============================");
    printf("\n\t VOLUME & LUAS.P BANGUN RUANG ");
    printf("\n\t==============================\n");
    printf("\t[1] Tabung\n");
    printf("\t[2] Bola\n");
    printf("\t[3] Limas Segiempat\n");
    printf("\t[4] Prisma Segitiga\n");
    printf("\t[5] Kerucut\n");
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
            tabung();
            break;
        case 2:
            bola();
            break;
        case 3:
            limas_segiempat();
            break;
        case 4:
            prisma_segitiga();
            break;
        case 5:
            kerucut();
            break;
    }
    ulang();

    return 0;
}