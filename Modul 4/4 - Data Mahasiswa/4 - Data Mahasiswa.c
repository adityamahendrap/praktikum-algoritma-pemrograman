#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Mahasiswa{
    int nim;
	char nama[50];
};

int check_nim(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah){
    int i;
    int exist = 0;

    for(i = 0; i < jumlah; i++){
        if(data.nim == data_tmp[i].nim){
            exist = 1;
            break;
        }else{
            exist = 0;
        }
    }
    return exist;
}

void set_data_temp(struct Mahasiswa data_tmp[]){
    int i;
    for(i = 0; i < 100; i++){
        data_tmp[i].nim = 0;
    }
}

int read_data_temp(struct Mahasiswa data_tmp[]){
    int jumlah = 0;

    FILE *read_tmp = fopen("DataMahasiswa.txt","r");
    if(!read_tmp){
        jumlah = 1;
    }else{
	    while(!feof(read_tmp)){
	   	    fscanf(read_tmp,"%d#%[^\n]\n", &data_tmp[jumlah].nim, &data_tmp[jumlah].nama);
            jumlah++;
	    }
    }
	fclose(read_tmp);
    return jumlah;
}

int input_nim(){
    char input[100];
    int i = 0;
    int error = 0;
    int result = 0;

    scanf("%[^\n]", &input);
    fflush(stdin);

    while(input[i] != '\0'){
        if(input[i] >= '0' && input[i] <= '9'){
            result = (result * 10) + (input[i] - 48);
            i++;
        }else{
            error = 1;
            input[i] = '\0';
        }
    }

    if(error == 1){
        printf("\n\tInvalid NIM! Masukkan lagi : ");
        return input_nim();
    }else{
        return result;
    }
}

void proses_insert(struct Mahasiswa data){
    FILE *insert = fopen("DataMahasiswa.txt", "a");
	fprintf(insert,"%d#%s\n", data.nim, data.nama);
	fclose(insert);
}

void insert_data(){
    int statusNim, statusNama, jumlah;
    struct Mahasiswa data;
    struct Mahasiswa data_tmp[100];

    set_data_temp(data_tmp);
    jumlah = read_data_temp(data_tmp);

    printf("\n\t-----------------------------------------------");
    printf("\n\t             Menambah Data Mahasiswa           ");
    printf("\n\t-----------------------------------------------");
	printf("\n\tMasukan NIM: ");
	fflush(stdin);
    data.nim = input_nim();
    statusNim = check_nim(data, data_tmp, jumlah);
    while(statusNim == 1){
        printf("\n\tNIM Sudah Ada! Masukan NIM Yang Baru: ");
        data.nim = input_nim();
        statusNim = check_nim(data, data_tmp, jumlah);
    }
	printf("\n\tMasukan Nama: ");
    scanf("%[^\n]", &data.nama);
    fflush(stdin);
    proses_insert(data);
}

void proses_show_data(struct Mahasiswa data_tmp[], int jumlah){
    int i;
    if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("\n\tTidak Ada Data");
    }else{
        for(i = 0; i < jumlah; i++){
            printf("\n\t%d. %d - %s", i+1, data_tmp[i].nim, data_tmp[i].nama);
        }
    }
}

void show_data(){
	int jumlah;
    struct Mahasiswa data_tmp[100];

    set_data_temp(data_tmp);
    jumlah = read_data_temp(data_tmp);

    printf("\n\t-----------------------------------------------");
    printf("\n\t           Menampilkan Data Mahasiswa          ");
    printf("\n\t-----------------------------------------------");
    printf("\n\tDaftar Data Mahasiswa :");
    proses_show_data(data_tmp, jumlah);
    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah Data : %d", jumlah);
    }
}

int main()
{
  int menu;
  printf("\n\t-----------------------------------------------");
  printf("\n\t     Program Sistem Informasi Mahasiswa        ");
  printf("\n\t-----------------------------------------------");  
  printf("\n\t[1] Menambah data mahasiswa");
  printf("\n\t[2] Membaca data mahasiswa");
  printf("\n\t[3] Keluar");
  printf("\n\t-----------------------------------------------"); 
  printf("\n\tMasukkan pilihan : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu >3)
  {
    printf("\n\tInvalid input!");
    printf("\n\tMasukan pilihan :  ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }

  if (menu == 1)
  {
    system("cls");
    insert_data();
  }
  else if (menu == 2)
  {
    system("cls");
    show_data();
  }
  else if (menu == 3)
  {
    system("cls");
    printf("\n\tProgram dihentikan\n");
    exit(1);
  }

  ulang();
  return 0;
}

void ulang()
{
  int menu;
  printf("\n\t-----------------------------------------------");
  printf("\n\t[1] Kembali");
  printf("\n\t[2] Keluar");
  printf("\n\t-----------------------------------------------");
  printf("\n\tMasukan Pilihan : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu >2)
  {
    printf("\n\tInvalid input!");
    printf("\n\tMasukan pilihan :  ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }

  switch (menu)
  {
  case 1:
    system("cls");
    main();
    break;
  case 2:
    system("cls");
    printf("\n\tProgram dihentikan\n");
    break;
  }
}