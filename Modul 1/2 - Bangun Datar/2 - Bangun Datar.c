#include <stdio.h>
#include <stdlib.h>
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

void segitiga_sembarang()
{
    double sisi1, sisi2, sisi3, s, s2, kll, luas;

    system("cls");
    printf("\n\t==============================");
    printf("\n\t      SEGITIGA SEMBARANG      ");
    printf("\n\t==============================\n");
    
    printf("\tMasukan sisi 1 : ");
    while (scanf("%lf", &sisi1) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi 1 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\tMasukan sisi 2 : ");
    while (scanf("%lf", &sisi2) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi 2 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\tMasukan sisi 3 : ");
    while (scanf("%lf", &sisi3) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi 3 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    kll = sisi1 + sisi2 + sisi3;
    s = ((sisi1 + sisi2 + sisi3))/2;
    s2 = (s * (s - sisi1) * (s - sisi2) * (s - sisi3));
    luas = sqrt(s2);
    
    printf("\n\tKELILING : %.2lf\n", kll);
    printf("\tLUAS     : %.2lf", luas);
    printf("\n\t==============================\n");
}

void belah_ketupat()
{
    double sisi, diagonal1, diagonal2, kll, luas;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t         BELAH KETUPAT        ");
    printf("\n\t==============================\n");

    printf("\tMasukan sisi       : ");
    while (scanf("%lf", &sisi) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi       : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan diagonal 1 : ");
    while (scanf("%lf", &diagonal1) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan diagonal 1 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan diagonal 2 : ");
    while (scanf("%lf", &diagonal2) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan diagonal 2 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    kll = 4 * sisi;
    luas = (diagonal1 * diagonal2)/2;
    printf("\n\tKELILING : %.2lf", kll);
    printf("\n\tLUAS     : %.2lf", luas);
    printf("\n\t==============================\n");
}

void jajar_genjang()
{
    double sisi1, sisi2, alas, tinggi, kll, luas;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t         JAJAR GENJANG        ");
    printf("\n\t==============================\n");
    
    printf("\tMasukan sisi 1 : ");
    while (scanf("%lf", &sisi1) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi 1 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan sisi 2 : ");
    while (scanf("%lf", &sisi2) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi 2 : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan alas   : ");
    while (scanf("%lf", &alas) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan alas   : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi : ");
    while (scanf("%lf", &tinggi) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    kll = 2 * (sisi1 + sisi2);
    luas =  alas * tinggi;
    printf("\n\tKELILING : %.2lf", kll);
    printf("\n\tLUAS     : %.2lf", luas);
    printf("\n\t==============================\n");
}

void trapesium()
{
    double sisi1, sisi2, sisi3, sisi4, alas, tinggi, kll, luas;
    
    system("cls");
    printf("\n\t==============================");
    printf("\n\t           TRAPESIUM          ");
    printf("\n\t==============================\n");
    
    printf("\tMasukan sisi atas  : ");
    while (scanf("%lf", &sisi1) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi atas  : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan sisi bawah : ");
    while (scanf("%lf", &sisi2) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi bawah : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan sisi kiri  : ");
    while (scanf("%lf", &sisi3) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan sisi kiri  : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan sisi kanan : ");
    while (scanf("%lf", &sisi4) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan kanan : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\tMasukan tinggi     : ");
    while (scanf("%lf", &tinggi) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan tinggi     : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    kll = sisi1 + sisi2 + sisi3 + sisi4;
    luas = (sisi1 + sisi2) * tinggi / 2;
    printf("\n\tKELILING : %.2lf", kll);
    printf("\n\tLUAS     : %.2lf", luas);
    printf("\n\t==============================\n");
}

void lingkaran()
{
    double r, kll, luas;

    system("cls");
    printf("\n\t==============================");
    printf("\n\t           LINGKARAN          ");
    printf("\n\t==============================\n");
    
    printf("\tMasukan jari-jari : ");
    while (scanf("%lf", &r) == 0)
    {
        printf("\n\tMasukan input dengan benar . . .\n");
        printf("\n\tMasukan jari-jari : ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    kll = 2 * PHI * r;
    luas = PHI * r * r;
    printf("\n\tKELILING : %.2lf", kll);
    printf("\n\tLUAS     : %.2lf", luas);
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
}

int main()
{
    int menu;

    system("cls");
    printf("\n\t==============================");
    printf("\n\t KELILING & LUAS BANGUN DATAR ");
    printf("\n\t==============================\n");
    printf("\t[1] Segitiga Sembarang\n");
    printf("\t[2] Belah Ketupat\n");
    printf("\t[3] Jajar Genjang\n");
    printf("\t[4] Trapesium\n");
    printf("\t[5] Lingkaran\n");
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
            segitiga_sembarang();
            break;
        case 2:
            belah_ketupat();
            break;
        case 3:
            jajar_genjang();
            break;
        case 4:
            trapesium();
            break;
        case 5:
            lingkaran();
            break;
    }
    ulang();

    return 0;
}