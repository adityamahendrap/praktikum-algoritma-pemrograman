#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int matriks1[3][3], matriks2[3][3];
int baris, kolom;

float func_input();

void judul()
{
  printf("\n\t+---------------------------------------------+");
  printf("\n\t|            Program Operasi Matriks          |");
  printf("\n\t+---------------------------------------------+\n");
}

void printMatrix(int matriks[3][3])
{
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      printf("\t%d", matriks[i][j]);
    }
    printf("\n");
  }
}

void createMatrix(int matriks[3][3])
{
  printf("\n\tMasukan baris matriks : ");
  baris = func_input();

  printf("\n\tMasukan kolom matriks : ");
  kolom = func_input();

  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      printf("\n\tMasukan Nilai baris %d kolom %d : ", i, j);
      matriks[i][j] = func_input();
    }
  }
}

void matrixAddition(int matriks1[3][3], int matriks2[3][3])
{
  int matriks3[3][3];
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      matriks3[i][j] = matriks1[i][j] + matriks2[i][j];
    }
  }

  printf("\n\tHasil Penjumlahan Matriks : \n\n");
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      printf("\t%d", matriks3[i][j]);
    }
    printf("\n");
  }
}

void matrixMultiplication(int matriks1[3][3], int matriks2[3][3])
{
  int matriks3[3][3];
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      matriks3[i][j] = 0;
      for (int k = 0; k < kolom; k++)
      {
        matriks3[i][j] += matriks1[i][k] * matriks2[k][j];
      }
    }
  }

  printf("\n\tHasil Perkalian Matriks : \n\n");
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      printf("\t%d", matriks3[i][j]);
    }
    printf("\n");
  }
}

void matrixTranspose(int matriks1[3][3])
{
  int matriks3[3][3];
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      matriks3[i][j] = matriks1[j][i];
    }
  }

  printf("\n\tHasil Transpose Matriks : \n\n");
  for (int i = 0; i < baris; i++)
  {
    for (int j = 0; j < kolom; j++)
    {
      printf("\t%d", matriks3[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int menu;
  printf("\n\t+---------------------------------------------+");
  printf("\n\t|            Program Operasi Matriks          |");
  printf("\n\t+---------------------------------------------+");
  printf("\n\t|                                             |");
  printf("\n\t|   [1] Penjumlahan Matriks                   |");
  printf("\n\t|   [2] Perkalian Matriks                     |");
  printf("\n\t|   [3] Transpose Matriks                     |");
  printf("\n\t|                                             |");
  printf("\n\t|   [4] Keluar                                |");
  printf("\n\t|                                             |");
  printf("\n\t+---------------------------------------------+");
  printf("\n\n\t>> ");
  menu = func_input();
  while (menu < 1 || menu > 4)
  {
    printf("\tInvalid input!");
    printf("\n\n\t>> ");
    menu = func_input();
  }

  system("cls");

  if (menu == 1)
  {
    judul();
    printf("\n\tBuat matriks pertama\n");
    createMatrix(matriks1);
    system("cls");

    judul();
    printf("\n\tBuat matriks kedua\n");
    createMatrix(matriks2);
    system("cls");

    judul();
    printf("\n\tMatriks pertama : \n\n");
    printMatrix(matriks1);

    printf("\n\tMatriks kedua : \n\n");
    printMatrix(matriks2);

    matrixAddition(matriks1, matriks2);
  }
  else if (menu == 2)
  {
    judul();
    printf("\n\tBuat matriks pertama\n");
    createMatrix(matriks1);
    system("cls");

    judul();
    printf("\n\tBuat matriks kedua\n");
    createMatrix(matriks2);
    system("cls");

    judul();
    printf("\n\tMatriks pertama : \n\n");
    printMatrix(matriks1);

    printf("\n\tMatriks kedua : \n\n");
    printMatrix(matriks2);

    matrixMultiplication(matriks1, matriks2);
  }
  else if (menu == 3)
  {
    judul();
    printf("\n\tBuat Matriks\n");
    createMatrix(matriks1);
    system("cls");

    judul();
    printf("\n\tMatriks : \n\n");
    printMatrix(matriks1);

    matrixTranspose(matriks1);
  }
  else if (menu == 4)
  {
    system("cls");
    printf("\n\t+---------------------------------------------+");
    printf("\n\t|           Program telah dihentikan          |");
    printf("\n\t+---------------------------------------------+\n");
    exit(1);
  }

  ulang();

  return 0;
}

void ulang()
{
  int menu;
  printf("\n\t+---------------------------------------------+");
  printf("\n\t|       [1] Ulangi           [2] Keluar       |");
  printf("\n\t+---------------------------------------------+");
  printf("\n\n\t>> ");
  menu = func_input();
  while (menu < 1 || menu > 2)
  {
    printf("\tInvalid input!");
    printf("\n\n\t>> ");
    menu = func_input();
  }

  if (menu == 1)
  {
    system("cls");
    main();
  }
  if (menu == 2)
  {
    system("cls");
    printf("\n\t+---------------------------------------------+");
    printf("\n\t|           Program telah dihentikan          |");
    printf("\n\t+---------------------------------------------+\n");
  }
}

float func_input()
{
  char input[5];
  int i = 0, error = 0, negative = 0, decimal = 0, whole_num = 0, fract_num = 0, chars = 0;
  float zero_point = 1, output;

  scanf("%s", input);

  if (input[i] == '\0')
  {
    error = 1;
  }

  while (input[i] != '\0')
  {
    if (input[i] == '-')
    {
      negative++;
      if (i > 0 || negative > 1)
      {
        error = 1;
        input[i] = '\0';
      }
      if (!isdigit(input[i + 1]))
      {
        error = 1;
        input[i] = '\0';
      }
      i++;
    }
    else if (input[i] == '.')
    {
      decimal++;
      if (decimal > 1 || input[i + 1] == '\0' || input[0] == '.')
      {
        error = 1;
        input[i] = '\0';
      }
      i++;
    }
    else if (isdigit(input[i]))
    {
      if (decimal == 1)
      {
        fract_num = (fract_num * 10) + (input[i] - 48);
        chars++;
        i++;
      }
      else
      {
        whole_num = (whole_num * 10) + (input[i] - 48);
        i++;
      }
    }
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  if (decimal == 1)
  {
    for (int j = 0; j < chars; j++)
    {
      zero_point /= 10;
    }
    output = fract_num * zero_point + whole_num;
  }
  else
  {
    output = whole_num;
  }

  if (negative == 1)
    output -= (output * 2);

  if (error == 1)
  {
    printf("\tInvalid input! ");
    printf("\n\n\t>> ");
    return func_input();
  }
  else
  {
    return output;
  }
}
