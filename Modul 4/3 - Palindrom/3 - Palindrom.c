#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void check_frequency(char *input, FILE *fptr)
{
  int i = 0, j, n, count = 0;
  for (j = 0; input[j]; j++);
  n = j;

  for (i; i < n; i++)
  {
    count = 1;
    if (input[i])
    {
      for (j = i + 1; j < n; j++)
      {

        if (input[i] == input[j])
        {
          count++;
          input[j] = '\0';
        }
      }
      fprintf(fptr, " %c=%d", input[i], count);
    }
  }
}

int checkpalindrom(char *input)
{
  for (int i = 0; i < strlen(input); i++)
  {
    if (input[i] != input[strlen(input) - i - 1])
      return 0;
  }
  return 1;
}

int main()
{
  char input[100], compare[100];
  FILE *fptr;
  int i = 0, j;

  printf("\n\t-----------------------------------------------");
  printf("\n\t          Program Pengecekan Palindrom         ");
  printf("\n\t-----------------------------------------------\n");
  printf("\n\tMasukan kata : ");
  fgets(input, sizeof(input), stdin);
  fflush(stdin);

  fptr = fopen("kamuskata.txt", "a+");

  if (fptr == NULL)
  {
    printf("\n\tTidak bisa membuka file..\n");
    exit(EXIT_FAILURE);
  }

  input[strlen(input) - 1] = '\0';

  fprintf(fptr, "%s(%d) :", input, strlen(input));

  while (input[i])
  {
    input[i] = tolower(input[i]);
    i++;
  }

  int isPalindrom = checkpalindrom(input);

  check_frequency(input, fptr);

  if (isPalindrom != 0)
    fprintf(fptr, " : Palindrom\n");
  else
    fprintf(fptr, " : Bukan Palindrom\n");
  fclose(fptr);

  printf("\n\t-----------------------------------------------");
  printf("\n\tKata yang anda masukan telah ditambahkan ke file");
  printf("\n\t-----------------------------------------------");

  ulang();
  return 0;
}

void ulang()
{
  int menu;
  printf("\n\t[1] Ulangi");
  printf("\n\t[2] Keluar");
  printf("\n\t-----------------------------------------------");
  printf("\n\tPilih Menu : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 2)
  {
      printf("\n\tInvalid input!");
      printf("\n\tMasukan kembali : ");
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
  }
  fflush(stdin);

  switch (menu)
  {
  case 1:
    system("cls");
    main();
    break;
  case 2:
    system("cls");
    printf("\n\tTerima kasih telah menggunakan program ini!\n");
    break;
  }
}