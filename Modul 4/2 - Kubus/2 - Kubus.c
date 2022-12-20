#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct KubusStruct
{
  float sisi;
  float lp;
  float volume;
};

union KubusUnion
{
  float sisi;
  float lp;
  float volume;
};

float func_input();

float lp_kubus(float sisi)
{
  return 6 * sisi * sisi;
}

float volume_kubus(float sisi)
{
  return sisi * sisi * sisi;
}

int main(void)
{
  struct KubusStruct kubusS;
  union KubusUnion kubusU[3];
  float sisi;

  printf("\n\t-----------------------------------------------");
  printf("\n\t       Program Luas Permukaan dan Volume       ");
  printf("\n\t         Kubus dengan Union dan Struct         ");
  printf("\n\t-----------------------------------------------");
  printf("\n\tMasukan panjang sisi kubus : ");
  sisi = func_input();

  kubusS.sisi = sisi;
  kubusS.lp = lp_kubus(sisi);
  kubusS.volume = volume_kubus(sisi);

  kubusU[0].sisi = sisi;
  kubusU[1].lp = lp_kubus(sisi);
  kubusU[2].volume = volume_kubus(sisi);

  printf("\n\tKubus dengan Struct");
  printf("\n\tSisi           : %.0f", kubusS.sisi);
  printf("\n\tLuas Permukaan : %.0f", kubusS.lp);
  printf("\n\tVolume         : %.0f\n", kubusS.volume);

  printf("\n\tKubus dengan Union");
  printf("\n\tSisi           : %.0f", kubusU[0].sisi);
  printf("\n\tLuas Permukaan : %.0f", kubusU[1].lp);
  printf("\n\tVolume         : %.0f\n", kubusU[2].volume);

  printf("\n\tUkuran memory pada kubus struct : %d", sizeof(kubusS));
  printf("\n\tUkuran memory pada kubus union : %d", sizeof(kubusU[0]));

  ulang();

  return 0;
}

void ulang()
{
  int menu;
  printf("\n\t-----------------------------------------------");
  printf("\n\t[1] Ulangi");
  printf("\n\t[2] Keluar");
  printf("\n\t-----------------------------------------------");
  printf("\n\tPilih Menu : ");
  menu = func_input();
  while(menu < 1 || menu > 2)
  {
    printf("\n\tInvalid input! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    menu = func_input();
  }

  switch (menu)
  {
  case 1:
    system("cls");
    main();
    break;
  case 2:
    system("cls");
    printf("\n\tProgram dihentikan!\n");
    break;
  }
}

float func_input()
{
  char input[5];
  int i = 0, error = 0, decimal = 0, whole_num = 0, fract_num = 0, chars = 0;
  float zero_point = 1, output;

  scanf("%s", input);

  if (input[i] == '\0')
    error = 1;

  while (input[i] != '\0')
  {
    if (input[i] == '.')
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
    output = whole_num;

  if (error == 1)
  {
    printf("\n\tYang anda masukan bukan angka! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return func_input();
  }
  else
    return output;
}
