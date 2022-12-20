#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int n;
clock_t waktu;
double waktu_bubble, waktu_bubble_pointer;

int func_input();

void print_data(int *data, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    printf("\n\tAngka ke-%d = %d ", i, data[i]);
  }
}

void copy_data(int *data, int *data_copy, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    data_copy[i] = data[i];
  }
}

void rand_data(int *data, int len)
{
  int i;
  srand(time(NULL));
  for (i = 0; i < len; i++)
  {
    data[i] = rand() % 1000;
  }
}

void bubbleSortPointer(int *data, int len)
{
    int temp, i, j;
    for(i = 0; i < len - 1; i++)
    {       
        for(j = 0; j < len - i - 1; j++)
        {          
            if(*(data + j) > *(data + j + 1))
            {               
                temp = *(data + j);
                *(data + j) = *(data + j + 1);
                *(data + j + 1) = temp;
            }
        }
    }
}

void bubbleSort(int *data, int len)
{
    int temp, i, j;

    for(i = 0; i < len - 1; i++)
    {       
        for(j = 0; j < len - i - 1; j++)
        {          
            if(data[j] > data[j + 1])
            {               
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void n_data()
{
  int input_n;
  system("cls");
  puts("+--------------------------+");
  puts("|        Bubble Sort       |");
  puts("|--------------------------|");
  puts("| Pilih Jumlah Data :      |");
  puts("| [1] 1000                 |");
  puts("| [2] 16000                |");
  puts("| [3] 64000                |");
  puts("|                          |");
  puts("| [4] Keluar               |");
  puts("+--------------------------+");
  printf(">> ");
  input_n = func_input();
  while (input_n < 1 || input_n > 4)
  {
    printf("\nInvalid Input!");
    printf("\n>> ");
    input_n = func_input();
  }

  if(input_n == 1)
    n = 1000;
  else if(input_n == 2)
    n = 16000;
  else if(input_n == 3) 
    n = 64000;   
  else if(input_n == 4)
  {
    system("cls");
    puts("+--------------------------+");
    puts("|    Program Dihentikan    |");
    puts("+--------------------------+");
    exit(1);
  }
    
}

void proses()
{
  int data1[n], data2[n];
  rand_data(data1, n);
  copy_data(data1, data2, n);

  waktu = clock();
  bubbleSort(data1, n);
  waktu = clock() - waktu;
  waktu_bubble = ((double)waktu) / CLOCKS_PER_SEC;

  waktu = clock();
  bubbleSortPointer(data2, n);
  waktu = clock() - waktu;
  waktu_bubble_pointer = ((double)waktu) / CLOCKS_PER_SEC;

  system("cls");
  puts("+--------------------------+");
  puts("|        Bubble Sort       |");
  puts("+--------------------------+");
  printf("\nWaktu Bubble Sort : %f", waktu_bubble);
  printf("\nWaktu Bubble Sort Pointer : %f\n", waktu_bubble_pointer);
}

int main()
{
  n_data();
  proses();
  ulang();

  return 0;
}

void ulang()
{
  int menu;
  puts("\n+--------------------------+");
  puts("|  [1] Ulang   [2] Keluar  |");
  puts("+--------------------------+");
  printf(">> ");
  menu = func_input();
  while (menu < 1 || menu > 2)
  {
    printf("\nInvalid Input!");
    printf("\n>> ");
    menu = func_input();
  }

  if(menu == 1) 
  {
    system("cls");
    main();
  }  
  else if(menu == 2)
  {
    system("cls");
    puts("+--------------------------+");
    puts("|    Program Dihentikan    |");
    puts("+--------------------------+");
  }  
}


int func_input()
{
  char input[5];
  int i = 0, output, error = 0;

  scanf("%s", input);

  if (input[i] == '\0')
  {
    error = 1;
  }

  while (input[i] != '\0')
  {
    if (isdigit(input[i]))
    {
      i++;
    }
    else
    {
      error = 1;
      input[i] = '\0';
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\n\tYang anda masukan bukan angka! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return func_input();
  }
  else
    return output;
}
