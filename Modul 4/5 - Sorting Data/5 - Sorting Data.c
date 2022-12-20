#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int mhs_index = 0;

struct Mahasiswa
{
  char nama[100];
  int nilai;
};

struct Mahasiswa mhs[8];

void sort_nilai()
{
  int i, j;
  struct Mahasiswa temp;
  for (i = 0; i < mhs_index; i++)
  {
    for (j = i + 1; j < mhs_index; j++)
    {
      if (mhs[i].nilai < mhs[j].nilai)
      {
        temp = mhs[i];
        mhs[i] = mhs[j];
        mhs[j] = temp;
      }
    }
  }
}

int main(void)
{
  int menu;
  FILE *fptr;

  printf("\n\t-----------------------------------------------");
  printf("\n\t            Sorting Nilai Mahasiswa            ");
  printf("\n\t-----------------------------------------------");
  printf("\n\t   [1] Sorting asistenin.txt");
  printf("\n\t   [2] Keluar");
  printf("\n\t-----------------------------------------------");
  printf("\n\t>> ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 2)
  {
    printf("\tInvalid input!");
    printf("\n\n\t>> ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }

  if (menu == 1)
  {
    fptr = fopen("asistenin.txt", "a+");

    if ((fptr = fopen("asistenin.txt", "r")) == NULL)
    {
      printf("Error: File tidak ada!");
      exit(1);
    }

    mhs_index = 0;
    memset(mhs, 0, sizeof(mhs));
    while (!feof(fptr))
    {
      fscanf(fptr, "%s", mhs[mhs_index].nama);
      fscanf(fptr, "%d", &mhs[mhs_index].nilai);
      mhs_index++;
    }

    fclose(fptr);

    sort_nilai();

    fptr = fopen("asistenout.txt", "a+");

    if ((fptr = fopen("asistenout.txt", "a")) == NULL)
    {
      printf("Error: File tidak ada!");
      exit(1);
    }

    fprintf(fptr, "Nilai Mata Kuliah Algoritma dan Pemrograman\n");
    for (int i = 0; i < mhs_index; i++)
    {
      fprintf(fptr, "%d. %s %d\n", i + 1, mhs[i].nama, mhs[i].nilai);
    }

    fclose(fptr);
    
    system("cls");
    printf("\n\t-----------------------------------------------");
    printf("\n\t Sorting berhasil! Silahkan cek asistenout.txt");
    printf("\n\t-----------------------------------------------\n\n");
  }
  else if (menu == 2)
  {
    system("cls");
    printf("\n\t-----------------------------------------------");
    printf("\n\t               Program dihentikan");
    printf("\n\t-----------------------------------------------\n\n");
  }

  return 0;
}
