#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int menu;

int input_int();

int validasi_teks(char *input)
{

  int i = 0, error = 0;

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isspace(input[i]))
      i++;
    else if (isalpha(input[i]))
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  if(menu == 1)
  {
    for(i = 0; input[i] != '\0'; i++)
    {
      if(isupper(input[i]) == 1)
      error = 1;
    }
  }

  if(menu == 2)
  {
    for(i = 0; input[i] != '\0'; i++)
    {
      if(islower(input[i]) == 2)
      error = 1;
    }
  }

  if (error == 1)
    return 0;
  else
    return 1;
}

void enkripsi(char *input, int key)
{
  int i;
  for(i = 0; input[i] != '\0'; i++)
  {
    if(input[i] == ' ')
      continue;

    if(input[i] < 120)
      input[i] = (input[i] + key);
    else 
      input[i] = (input[i] + key) - 26;

    input[i] = toupper(input[i]);
  }
}

void deskripsi(char *input, int key)
{
  int i;
  for(i = 0; input[i] != '\0'; i++)
  {
    if(input[i] == ' ')
      continue;

    if(input[i] < 120)
      input[i] = (input[i] - key);
    else 
      input[i] = (input[i] - key) + 26;

    input[i] = tolower(input[i]);
  }
}

void enkripsi_menu()
{
  char teks[100];
  int n;
  printf("\n\t-----------------------------------------------");
  printf("\n\t               Program Enkripsi                ");
  printf("\n\t-----------------------------------------------");
  printf("\n\tMasukan jumlah pergeseran : ");
  n = input_int();
  printf("\n\tMasukan plaintext : ");
  fflush(stdin);
  fgets(teks, sizeof(teks), stdin);
  while (validasi_teks(teks) == 0)
  {
    printf("\n\tHanya boleh berisi huruf kecil! ");
    printf("\n\tSilahkan masukan kembali : ");
    fgets(teks, sizeof(teks), stdin);
  }

  printf("\n\tTeks sebelum dienkripsi : %s", teks);

  enkripsi(teks, n);

  printf("\n\tTeks setelah dienkripsi : %s", teks);
  printf("\n\t-----------------------------------------------");
}

void deskripsi_menu()
{
  char teks[100];
  int n;
  printf("\n\t-----------------------------------------------");
  printf("\n\t              Program Deskripsi                ");
  printf("\n\t-----------------------------------------------");
  printf("\n\tMasukan jumlah pergeseran : ");
  n = input_int();
  printf("\n\tMasukan ciphertext : ");
  fflush(stdin);
  fgets(teks, sizeof(teks), stdin);
  while (validasi_teks(teks) == 0)
  {
    printf("\n\tHanya boleh berisi huruf besar! ");
    printf("\n\tSilahkan masukan kembali : ");
    fgets(teks, sizeof(teks), stdin);
  }

  printf("\n\tTeks sebelum dideskripsi : %s", teks);

  deskripsi(teks, n);

  printf("\n\tTeks setelah dideskripsi : %s", teks);
  printf("\n\t-----------------------------------------------");
}

int main(void)
{
  printf("\n\t-----------------------------------------------");
  printf("\n\t         Program Enkripsi dan Deskripsi        ");
  printf("\n\t-----------------------------------------------");
  printf("\n\t [1] Enkripsi");
  printf("\n\t [2] Deskripsi");
  printf("\n\t [3] Keluar");
  printf("\n\t-----------------------------------------------");
  printf("\n\t>> ");
  menu = input_int();
  while(menu < 1 || menu > 3)
  {
    printf("\tInvalid input!");
    printf("\n\n\tMasukan Kembali : ");
    menu = input_int();
  }

  switch (menu)
  {
  case 1:
    system("cls");
    enkripsi_menu();
    break;
  case 2:
    system("cls");
    deskripsi_menu();
    break;
  case 3:
    system("cls");
    printf("\n\tProgram telah dihentikan\n");
    break;
  }

  ulang();
  return 0;
}

void ulang()
{
  int menu2;
  printf("\n\t [1] Ulangi");
  printf("\n\t [2] Keluar");
  printf("\n\t-----------------------------------------------");
  printf("\n\t>> ");
  menu2 = input_int();
  while(menu2 < 1 || menu2 > 2)
  {
    printf("\tInvalid input!");
    printf("\n\n\tMasukan kembali : ");
    menu2 = input_int();
  }
  fflush(stdin);

  switch (menu2)
  {
  case 1:
    system("cls");
    main();
    break;
  case 2:
    system("cls");
    printf("\n\tProgram telah dihentikan\n");
    break;
  }
}

int input_int()
{
  char input[5];
  int i = 0, output, error = 0;

  scanf("%s", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
      i++;
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\tInvalid input! ");
    printf("\n\n\tMasukan kembali : ");
    return input_int();
  }
  else
    return output;
}
