#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int d, m, opsi;
    do{
        system("cls");
        printf("\n");
        printf("\t==============================\n");
        printf("\t|       ZODIAC COVERTER      |\n");
        printf("\t==============================\n");

        printf("\n\tMasukan tanggal : ");
        while (scanf("%d", &d) == 0)
        {
            printf("\tInput tidak valid . . .\n\n");
            printf("\tMasukan tanggal : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        printf("\tMasukan bulan   : ");
        while (scanf("%d", &m) == 0)
        {
            printf("\tInput tidak valid . . .\n\n");
            printf("\tMasukan bulan   : ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        zodiac(d, m);

        printf("\n\n");
        printf("\t==============================\n");
        printf("\t|   [1] Ulangi  [2] Keluar   |\n");
        printf("\t==============================\n");
        printf("\n\t>> ");
        while (scanf("%d", &opsi) == 0 || opsi < 1 || opsi > 2)
        {
            printf("\tInput tidak valid . . .");
            printf("\n\n\t>> ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while(opsi != 2);
    keluar();

    return 0;
}

void zodiac(int d, int m)
{
    if(((d >= 21 && d <= 31) && m == 3) || (((d >= 1 && d <= 19) && m == 4))) 
    {            
        printf("\n\tZodiakmu adalah ARIES");
    } 
    else if(((d >= 20 && d <= 30) && m == 4) || (((d >= 1 && d <= 20) && m == 5))) 
    {            
        printf("\n\tZodiakmu adalah TAURUS");
    } 
    else if(((d >= 21 && d <= 31) && m == 5) || (((d >= 1 && d <= 20) && m == 6))) 
    {           
        printf("\n\tZodiakmu adalah GEMINI");
    } 
    else if(((d >= 21 && d <= 30) && m == 6) || (((d >= 1 && d <= 22) && m == 7))) 
    {          
        printf("\n\tZodiakmu adalah CANCER");
    }
    else if(((d >= 23 && d <= 31) && m == 7) || (((d >= 1 && d <= 22) && m == 8))) 
    {           
        printf("\n\tZodiakmu adalah LEO");
    }
    else if(((d >= 23 && d <= 31) && m == 8) || (((d >= 1 && d <= 22) && m == 9))) 
    {            
        printf("\n\tZodiakmu adalah VIRGO");
    }
    else if(((d >= 23 && d <= 30) && m == 9) || (((d >= 1 && d <= 22) && m == 10))) 
    {             
        printf("\n\tZodiakmu adalah LIBRA");
    }
    else if(((d >= 23 && d <= 31) && m == 10) || (((d >= 1 && d <= 21) && m == 11))) 
    {             
        printf("\n\tZodiakmu adalah SCORPIO");
    }
    else if(((d >= 22 && d <= 30) && m == 11) || (((d >= 1 && d <= 21) && m == 12))) 
    {             
        printf("\n\tZodiakmu adalah SAGITARIUS");
    }
    else if(((d >= 22 && d <= 31) && m == 12) || (((d >= 1 && d <= 19) && m == 1))) 
    {            
        printf("\n\tZodiakmu adalah CAPRICORN");
    }
    else if(((d >= 20 && d <= 31) && m == 1) || (((d >= 1 && d <= 18) && m == 2))) 
    {           
        printf("\n\tZodiakmu adalah AQUARIUS");
    }
    else if(((d >= 19 && d <= 29) && m == 2) || (((d >= 1 && d <= 20) && m == 3))) 
    {            
        printf("\n\tZodiakmu adalah PISCES");
    }
    else
    {
        printf("\n");
        printf("\t==============================\n");
        printf("\t|     WAKTU TIDAK VALID      |\n");
        printf("\t==============================\n");
        printf("\n\tTekan apapun untuk mengulang . . .");
        getch();
        main();
    }
}

void keluar()
{
    system("cls");
    printf("\n\t==============================");
    printf("\n\t|                            |");
    printf("\n\t|     Terimakasih telah      |");
    printf("\n\t|   menggunakan program ini  |");
    printf("\n\t|                            |");
    printf("\n\t==============================\n\n");
}