#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double hitungAbsensi(int absensi)
{
    return (absensi / 15) * 100 * 0.05;
}

double hitungTugas(double tugas1, double tugas2, double tugas3)
{
    return ((tugas1 + tugas2 + tugas3) / 3) * 0.20;
}

double hitungQuiz(double quiz)
{
    return quiz * 0.15;
}

double hitungUTS(double uts)
{
    return uts * 0.30;
}

double hitungUAS(double uas)
{
    return uas * 0.30;
}

void nAkhir(double nAngka)
{
    if(nAngka >= 0 && nAngka < 45) 
    {
        printf("\n\t===================================");
        printf("\n\t                 E                 ");
        printf("\n\t===================================");
    } 
    else if(nAngka >= 45 && nAngka < 50) 
    {
        printf("\n\t===================================");
        printf("\n\t                 D                 ");
        printf("\n\t===================================");
    }
    else if(nAngka >= 50 && nAngka < 55) 
    {
        printf("\n\t===================================");
        printf("\n\t                 D+                ");
        printf("\n\t===================================");
    }
    else if(nAngka >= 55 && nAngka < 60) 
    {
        printf("\n\t===================================");
        printf("\n\t                 C                 ");
        printf("\n\t===================================");
    }
    else if(nAngka >= 60 && nAngka < 65) 
    {
        printf("\n\t===================================");
        printf("\n\t                 C+                ");
        printf("\n\t===================================");
    }
    else if(nAngka >= 65 && nAngka < 75) 
    {
        printf("\n\t===================================");
        printf("\n\t                 B                 ");
        printf("\n\t===================================");
    }
    else if(nAngka >= 75 && nAngka < 80) 
    {
        printf("\n\t===================================");
        printf("\n\t                 B+                ");
        printf("\n\t===================================");
    }
    else if(nAngka >= 80 && nAngka <= 100) 
    {
        printf("\n\t===================================");
        printf("\n\t                 A                 ");
        printf("\n\t===================================");
    }
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

int main() {
    
    int opsi, absensi;
    double nAngka, tugas1, tugas2, tugas3, quiz, uts, uas;
    do{
        system("cls");
        printf("\n\t===================================");
        printf("\n\t        PROGRAM NILAI AKHIR        ");
        printf("\n\t===================================\n");
        printf("\n\tMasukan kehadiran (max. 15) : ");
        while (scanf("%d", &absensi) == 0 || absensi < 0 || absensi > 15)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan kehadiran (max. 15) : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("\n\tMasukan nilai tugas 1 : ");
        while (scanf("%lf", &tugas1) == 0 || tugas1 < 0 || tugas1 > 100)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan nilai tugas 1 : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("\n\tMasukan nilai tugas 2 : ");
        while (scanf("%lf", &tugas2) == 0 || tugas2 < 0 || tugas2 > 100)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan nilai tugas 2 : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("\n\tMasukan nilai tugas 3 : ");
        while (scanf("%lf", &tugas3) == 0 || tugas3 < 0 || tugas3 > 100)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan nilai tugas 3 : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("\n\tMasukan nilai quiz    : ");
        while (scanf("%lf", &quiz) == 0 || quiz < 0 || quiz > 100)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan nilai quiz    : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("\n\tMasukan nilai UTS     : ");
        while (scanf("%lf", &uts) == 0 || uts < 0 || uts > 100)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan nilai UTS     : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("\n\tMasukan nilai UAS     : ");
        while (scanf("%lf", &uas) == 0 || uas < 0 || uas > 100)
        {
            printf("\tMasukan input dengan benar . . .\n");
            printf("\n\tMasukan nilai UAS     : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        double nAbsensi = hitungAbsensi(absensi);
        double nTugas = hitungTugas(tugas1, tugas2, tugas3);
        double nQuiz = hitungQuiz(quiz);
        double nUTS = hitungUTS(uts);
        double nUAS = hitungUAS(uas);

        nAngka = nAbsensi + nTugas + nQuiz + nUTS + nUAS;

        printf("\n\tNilai akhirnya adalah %.2lf\n", nAngka);
        nAkhir(nAngka);

        getch();
        system("cls");
        printf("\n\t===================================");
        printf("\n\t        PROGRAM NILAI AKHIR        ");
        printf("\n\t===================================");
        printf("\n\t[1] Ulangi");
        printf("\n\t[2] Keluar");
        printf("\n\t===================================");
        printf("\n\t>> ");
        while (scanf("%d", &opsi) == 0 || opsi < 1 || opsi > 2)
        {
            printf("\n\tInvalid input . . .");
            printf("\n\t>> ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while(opsi != 2);
    keluar();

    return 0;
}


