#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func_input();

float median(float *arr, int n)
{
  float temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  if (n % 2 == 0)
  {
    return (arr[n / 2] + arr[(n / 2) - 1]) / 2;
  }
  else
  {
    return arr[n / 2];
  }
}

float mean(float *arr, int n)
{
  float sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum / n;
}

float modus(float *arr, int n)
{
  int count = 1, max = 0;
  float modus = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }
    if (count > max)
    {
      max = count;
      modus = arr[i];
      if(max == 1)
      {
        modus = 0;
      }
    }
    count = 1;
  }
  return modus;
}

int main()
{
  int n;
  float data[100];

  judulprogram();
  printf("\n\n\t\t\t\t\tMasukkan jumlah data : ");
  n = func_input();

  while(n == 0)
  {
    try();
    n = func_input();
  }
  
	for (int i = 0; i < n; i++)
  {
    printf("\n\t\t\t\t\tMasukan data ke-%d : ", i + 1);
    data[i] = func_input();
  }

  system("cls");
  judulprogram();

  printf("\n\n\t\t\t\t\tMean   : %.1f", mean(data, n));
  printf("\n\n\t\t\t\t\tMedian : %.1f", median(data, n));
  printf("\n\n\t\t\t\t\tModus  : %.0f", modus(data, n));

	ulang();
}

void judulprogram(){
    system("cls");
    printf("\n\t\t\t\t\t+-----------------------------------+");
    printf("\n\t\t\t\t\t|         Program Statistika        |");
    printf("\n\t\t\t\t\t+-----------------------------------+");
}

void try()
{
  printf("\n\t\t\t\t\tInput kurang tepat! ");
  printf("\n\t\t\t\t\tSilahkan masukan kembali : ");
}

void ulang(){
  int menu;
  printf("\n");
  printf("\n\t\t\t\t\t+-----------------------------------+");
  printf("\n\t\t\t\t\t|      [1] Ulangi    [2] Keluar     |");
  printf("\n\t\t\t\t\t+-----------------------------------+");
  printf("\n");
  printf("\n\t\t\t\t\t>> ");
  menu = func_input();
  while (menu < 1 || menu > 2)
  {
    try();
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
    keluar();
    break;
  }
}

void keluar()
{
    printf("\n\t\t\t\t\t+-----------------------------------+");
    printf("\n\t\t\t\t\t|        Program Dihentikan         |");
    printf("\n\t\t\t\t\t+-----------------------------------+");
    printf("\n\n");
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
      if (i > 0 || negative > 0)
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
    printf("\n\t\t\t\t\tInput kurang tepat! ");
    printf("\n\t\t\t\t\tSilahkan masukan kembali : ");
    return func_input();
  }
  else
    return output;
}
