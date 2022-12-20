#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define GAJI_PER_JAM 10625

struct Pegawai
{
  float gajiPokok;
  float gajiLembur;
  float gajiTotal;
  int jmlJamKerja;
};

int func_input();

int main()
{
  struct Pegawai pegawai;

  printf("\n\t-----------------------------------------------");
  printf("\n\t             Program Gaji Harian               ");
  printf("\n\t-----------------------------------------------");

  printf("\n\n\tMasukan jumlah jam kerja : ");
  pegawai.jmlJamKerja = func_input();
  while (pegawai.jmlJamKerja > 24)
  {
    printf("\n\tJam kerja maksimal 24 jam! ");
    printf("\n\tSilahkan masukan kembali : ");
    pegawai.jmlJamKerja = func_input();
  }

  if (pegawai.jmlJamKerja > 8)
  {
    pegawai.gajiPokok = 8 * GAJI_PER_JAM;
    pegawai.gajiLembur = ((float)pegawai.jmlJamKerja - 8) * GAJI_PER_JAM;
  }
  else
  {
    pegawai.gajiPokok = (float)pegawai.jmlJamKerja * GAJI_PER_JAM;
    pegawai.gajiLembur = 0;
  }

  pegawai.gajiTotal = pegawai.gajiPokok + pegawai.gajiLembur;

  printf("\n\tGaji Pokok  : Rp. %.0f", pegawai.gajiPokok);
  printf("\n\tGaji Lembur : Rp. %.0f", pegawai.gajiLembur);
  printf("\n\tGaji Total  : Rp. %0.f\n", pegawai.gajiTotal);

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
    printf("\n\t-----------------------------------------------");
    printf("\n\t             Program telah dihentikan          ");
    printf("\n\t-----------------------------------------------\n");
    break;
  }
}

int func_input()
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
    printf("\n\tInvalid input! ");
    printf("\n\tSilahkan masukan angka kembali : ");
    return func_input();
  }
  else
    return output;
}