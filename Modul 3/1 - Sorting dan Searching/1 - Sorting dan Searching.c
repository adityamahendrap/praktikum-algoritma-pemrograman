#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int n, input_n;
size_t waktu;

struct Result
{
  double insertion;
  double bubble;
  double quick;
  double sequential;
  double binary;
};

struct Result result;

void insertionSort(int *data, int len) {
  int i, j, temp;
  for (i = 1; i < len; i++) {
    temp = data[i];
    j = i - 1;
    while (temp < data[j] && j >= 0) {
      data[j + 1] = data[j];
      --j;
    }
    data[j + 1] = temp;
  }
}

void bubbleSort(int *data, int len)
{
    int temp, i, j;

    for(i = 0; i < len - 1; i++){       
        for(j = 0; j < len - i - 1; j++){          
            if(data[j] > data[j + 1]){               
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void quickSort(int *data,int first,int last){
   int i, j, pivot, temp;
   if(first < last){
      pivot = first;
      i = first;
      j = last;
      while(i < j){
         while(data[i] <= data[pivot] && i < last)
         i++;
         while(data[j] > data[pivot])
         j--;
         if(i<j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
         }
      }
      temp = data[pivot];
      data[pivot] = data[j];
      data[j] = temp;
      quickSort(data, first, j-1);
      quickSort(data, j+1, last);
   }
}

void sequentialSearch(int *data, int len, int key)
{
    int flag, index;
    for(int i = 0; i < len; i++)
    {
        if(key == data[i])
        {
            flag = 1;
            index = i;
        }
    }
  if (flag == 1)
    printf("\nAngka %d ditemukan pada indeks ke-%d", key, index);
  else
    printf("\nAngka %d tidak ditemukan", key);
}

int binarySearch(int *data, int len, int key) {
  int left, right, mid, found = 0;
  left = 0;
  right = len - 1;
  while (left <= right)
  {
    mid = (left + right) / 2;
    if (data[mid] == key)
    {
      found = 1;
      break;
    }
    else if (data[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  if (found == 1)
    printf("\nAngka %d ditemukan pada indeks ke-%d", key, mid);
  else
    printf("\nAngka %d tidak ditemukan", key);
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

void copy_data(int *data, int *data_copy, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    data_copy[i] = data[i];
  }
}

void sorting()
{
  system("cls");
  int data1[n], data2[n], data3[n];

  rand_data(data1, n);
  copy_data(data1, data2, n);
  copy_data(data1, data3, n);

  waktu = clock();
  insertionSort(data1, n);
  waktu = clock() - waktu;
  result.insertion = ((double)waktu) / CLOCKS_PER_SEC;

  waktu = clock();
  bubbleSort(data2, n);
  waktu = clock() - waktu;
  result.bubble = ((double)waktu) / CLOCKS_PER_SEC;

  waktu = clock();
  quickSort(data3, 0, n - 1);
  waktu = clock() - waktu;
  result.quick = ((double)waktu) / CLOCKS_PER_SEC;

  puts("+--------------------------+");
  puts("|          Sorting         |");
  puts("+--------------------------+");

  printf("\nJumlah Data : %d\n", n);
  printf("\nWaktu insertion sort : %f", result.insertion);
  printf("\nWaktu bubble sort    : %f", result.bubble);
  printf("\nWaktu quick sort     : %f", result.quick);
  printf("\n");

  if (result.insertion < result.bubble && result.insertion < result.quick)
    printf("\nInsertion sort paling cepat");
  else if (result.bubble < result.insertion && result.bubble < result.quick)
    printf("\nBubble sort paling cepat");
  else if (result.quick < result.insertion && result.quick < result.bubble)
    printf("\nQuick sort paling cepat");
  else
    printf("\nWaktu proses sama");
}

void searching()
{
    int key;
    int data1[n], data2[n], data3[n];
    rand_data(data1, n);
    copy_data(data1, data2, n);
    
    system("cls");
    puts("+--------------------------+");
    puts("|         Searching        |");
    puts("+--------------------------+");
    printf("\nMasukan angka dicari : ");
    key = func_input();

    system("cls");
    puts("+--------------------------+");
    puts("|         Searching        |");
    puts("+--------------------------+");
    printf("\nAngka yang dicari : %d", key);

    printf("\n\nPencarian dengan sequential search : ");
    waktu = clock();
    sequentialSearch(data1, n, key);
    waktu = clock() - waktu;
    result.sequential = ((double)waktu) / CLOCKS_PER_SEC;

    printf("\nPencarian dengan binary search : ");
    waktu = clock();
    binarySearch(data2, n, key);
    waktu = clock() - waktu;
    result.binary = ((double)waktu) / CLOCKS_PER_SEC;

    printf("\n\nWaktu proses sequential search : %f", result.sequential);
    printf("\nWaktu proses binary search : %f\n", result.binary);

  if (result.sequential < result.binary)
    printf("\nSequential search paling cepat");
  else if (result.binary < result.sequential)
    printf("\nBinary search paling cepat");
  else
    printf("\nWaktu proses sama");
}

int main() 
{
  int menu, menu2;
  puts("+--------------------------+");
  puts("|   Sorting dan Sarching   |");
  puts("|--------------------------|");
  puts("| [1] Sorting              |");
  puts("| [2] Searching            |");
  puts("+--------------------------+");
  printf(">> ");
  menu = func_input();
  while (menu < 1 || menu > 2)
  {
    printf("\nInvalid Input!");
    printf("\n>> ");
    menu = func_input();
  }

  n_data();
  
  if(menu == 1)   
    sorting();
  else if(menu == 2)
    searching();

  printf("\n\n");
  puts("+--------------------------+");
  puts("|  [1] Ulangi  [2] Keluar  |");
  puts("+--------------------------+");
  printf(">> ");
  menu2 = func_input();
  while (menu2 < 1 || menu2 > 2)
  {
    printf("\nInvalid Input!");
    printf("\n>> ");
    menu2 = func_input();
  }

  if(menu2 == 1) 
  {
    system("cls");
    main();
  }  
  else if(menu2 == 2)
  {
    system("cls");
    puts("+--------------------------+");
    puts("|    Program Dihentikan    |");
    puts("+--------------------------+");
  }  

  return 0;
}

void n_data()
{
  int input_n;
  system("cls");
  puts("+--------------------------+");
  puts("|        Jumlah Data       |");
  puts("|--------------------------|");
  puts("| [1] 1000                 |");
  puts("| [2] 16000                |");
  puts("| [3] 64000                |");
  puts("+--------------------------+");
  printf(">> ");
  input_n = func_input();
  while (input_n < 1 || input_n > 3)
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
    printf("Invalid Input! ");
    printf("\n\n>> ");
    return func_input();
  }
  else
    return output;
}