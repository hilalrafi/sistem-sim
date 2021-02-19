#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Kamus
typedef struct
{
    char ndpn[100];
    char nblkg[100];
    char n_lngkp[100];
}nama;

typedef struct
{
    int tgl;
    int bln;
    int thn;
}date;

typedef struct
{
    char jalan[100];
    char desa[100];
    int rt;
    int rw;
    char kecamatan[50];
    char kabupaten_kota[50];
}alamat;

typedef struct
{
    nama nama_lngkp;
    date ttl;
    char tempat[50];
    alamat alamat_lngkp;
    int tinggi;
    char pekerjaan[50];
    int no_sim;
    date tgl_kadal;
    char jenis_sim[10];
}sim;

sim sim_s[100];
int banyak,x,y,cari,cari_no;
char cari_nama[100],cari_jenis[10],tampung[100];
void judul_program();
void tampi_data();
void cari_data();
void urutkan_data();
void tampil_urutan();

/// Deskripsi

/// Prosedur untuk menampilkan judul program
void judul_program()
{
    puts("==================================================");
    puts("||\t\tSistem Input Data SIM\t\t||");
    puts("==================================================");
}

/// Prosedur untuk menampilkan data
void tampi_data()
{
    printf("Nama\t\t\t\t: %s\n",sim_s[x].nama_lngkp.n_lngkp);
    printf("Tempat lahir\t\t\t: %s\n",sim_s[x].tempat);
    printf("Tanggal lahir\t\t\t: %d-%d-%d\n",sim_s[x].ttl.tgl,sim_s[x].ttl.bln,sim_s[x].ttl.thn);
    printf("Alamat\n");
    printf("Jalan\t\t\t\t: %s\n",sim_s[x].alamat_lngkp.jalan);
    printf("Desa\t\t\t\t: %s\n",sim_s[x].alamat_lngkp.desa);
    printf("RT\t\t\t\t: %d\n",sim_s[x].alamat_lngkp.rt);
    printf("RW\t\t\t\t: %d\n",sim_s[x].alamat_lngkp.rw);
    printf("Kecamatan\t\t\t: %s\n",sim_s[x].alamat_lngkp.kecamatan);
    printf("Kabupaten / Kota\t\t: %s\n",sim_s[x].alamat_lngkp.kabupaten_kota);
    printf("Tinggi Badan\t\t\t: %d cm\n",sim_s[x].tinggi);
    printf("Pekerjaan\t\t\t: %s\n",sim_s[x].pekerjaan);
    printf("Nomor SIM\t\t\t: %d\n",sim_s[x].no_sim);
    printf("Tanggal berlaku\t\t\t: %d-%d-%d\n",sim_s[x].tgl_kadal.tgl,sim_s[x].tgl_kadal,sim_s[x].tgl_kadal.thn);
    printf("Jenis SIM (A / B1 / B2 / C / D)\t: %s\n",sim_s[x].jenis_sim);
}

/// prosedur untuk mencari sebuah data
void cari_data()
{
    puts("\n===========================");
    printf("Cari data Berdasarkan ?\n");
    printf("1. Nama\n");
    printf("2. No. SIM\n");
    printf("3. Jenis SIM\n");
    printf("Pilih salah satu : "); scanf("%d",&cari);
    switch (cari)
    {
        case 1:
            printf("Masukkan Nama yang dicari : "); fflush(stdin); gets(cari_nama);
            printf("\n");
            x=0;
            while (x < banyak)
            {
                if (strcmp(cari_nama,sim_s[x].nama_lngkp.n_lngkp) == 0)
                {
                    tampi_data();
                }
                x+=1;
            }
            break;
        case 2:
            printf("Masukkan No.SIM yang dicari : "); scanf("%d",&cari_no);
            printf("\n");
            x=0;
            while (x < banyak)
            {
                if (cari_no == sim_s[x].no_sim)
                {
                    tampi_data();
                }
                x+=1;
            }
            break;
        case 3:
            printf("Masukkan Jenis SIM yang dicari : "); fflush(stdin); gets(cari_jenis);
            printf("\n");
            x=0;
            while (x < banyak)
            {
                if (strcmp(cari_jenis,sim_s[x].jenis_sim) == 0)
                {
                    tampi_data();
                }
                x+=1;
            }
            break;
        default:
            puts(" ");
            break;
    }
}

/// Prosedur Mengurutkan data dengan metode bubble sort
void urutkan_data()
{
    x=0;
    while (x < banyak-1)
    {
        y=0;
        while (y < banyak-x-1)
        {
            if (strcmp(sim_s[y].nama_lngkp.n_lngkp, sim_s[y+1].nama_lngkp.n_lngkp) > 0)
            {
                strcpy(tampung,sim_s[y].nama_lngkp.n_lngkp);
                strcpy(sim_s[y].nama_lngkp.n_lngkp,sim_s[y+1].nama_lngkp.n_lngkp);
                strcpy(sim_s[y+1].nama_lngkp.n_lngkp,tampung);
            }
            y+=1;
        }
        x+=1;
    }
}

/// Prosedur Menampilkan sorting data
void tampil_urutan()
{
    urutkan_data();
    puts("\n==========================");
    puts("Urutan Data : ");
    x=0;
    while (x < banyak)
    {
        printf("%d. %s\n",x+1,sim_s[x].nama_lngkp.n_lngkp);
        x+=1;
    }
}

int main()
{
    judul_program(); /// memanggil prosedur sebuah judul program
    printf("\nInput data sebanyak ? "); scanf("%d",&banyak);    /// ipnutkan banyak data yang diinginkan
    x=0;
    while (x < banyak)
    {
        printf("Nama Depan\t: "); fflush(stdin); gets(sim_s[x].nama_lngkp.ndpn);
        printf("Nama Belakang\t: "); fflush(stdin); gets(sim_s[x].nama_lngkp.nblkg);
        printf("Nama Lengkap\t: "); fflush(stdin); gets(sim_s[x].nama_lngkp.n_lngkp);
        printf("Tempat lahir\t: "); scanf("%s",&sim_s[x].tempat);
        printf("\nTanggal lahir\n");
        printf("Tangaal\t\t: "); scanf("%d",&sim_s[x].ttl.tgl);
        printf("Bulan\t\t: "); scanf("%d",&sim_s[x].ttl.bln);
        printf("Tahun\t\t: "); scanf("%d",&sim_s[x].ttl.thn);
        printf("\nAlamat\n");
        printf("Jalan\t\t: "); fflush(stdin); gets(sim_s[x].alamat_lngkp.jalan);
        printf("Desa\t\t: "); fflush(stdin); gets(sim_s[x].alamat_lngkp.desa);
        printf("RT\t\t: "); scanf("%d",&sim_s[x].alamat_lngkp.rt);
        printf("RW\t\t: "); scanf("%d",&sim_s[x].alamat_lngkp.rw);
        printf("Kecamatan\t: "); fflush(stdin); gets(sim_s[x].alamat_lngkp.kecamatan);
        printf("Kabupaten / Kota\t: "); fflush(stdin); gets(sim_s[x].alamat_lngkp.kabupaten_kota);
        printf("Tinggi Badan\t: "); scanf("%d",&sim_s[x].tinggi);
        printf("Pekerjaan\t: "); scanf("%s",&sim_s[x].pekerjaan);
        printf("Nomor SIM\t: "); scanf("%d",&sim_s[x].no_sim);
        printf("\nTanggal Berlaku\n");
        printf("Tangaal\t\t: "); scanf("%d",&sim_s[x].tgl_kadal.tgl);
        printf("Bulan\t\t: "); scanf("%d",&sim_s[x].tgl_kadal.bln);
        printf("Tahun\t\t: "); scanf("%d",&sim_s[x].tgl_kadal.thn);
        printf("Jenis SIM (A / B1 / B2 / C / D): "); fflush(stdin); gets(sim_s[x].jenis_sim);
        printf("\n");
        x+=1;
    }
    cari_data();        /// memanggil prosedur cari data
    tampil_urutan();    /// memanggil prosedur tampil_urutan
    return 0;
}
