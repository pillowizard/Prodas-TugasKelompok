#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
//deklarasi variable global
int i,x,y;
int kode_cari;
bool ketemu;
int b_array;
int p_array;
int k_array;
int menu;
int menu_bk;
int menu_pinjam;
int menu_kembali;
    

//deklarasi struct
typedef struct
{
    int tgl;
    int bln;
    int thn;    
} tanggal;

typedef struct
{
    int kode;
    char judul[31];
    char pengarang[31];
    char penerbit[31];
    int stok;    
} buku;

typedef struct
{
    int kode_peminjaman;    
    char nama_peminjam[31];
    char alamat_peminjam[51];
    int kode_buku;
    char judul_buku[31];
    tanggal tgl_pinjam;    
} peminjaman;

typedef struct
{
    int kode_peminjaman;    
    char nama_peminjam[31];
    char alamat_peminjam[51];
    int kode_buku;
    char judul_buku[31];
    tanggal tgl_kembali;
    int lama;
    int denda;    
} pengembalian;

//deklarasi array of struct
buku bk[100];
peminjaman pinjam[200];
pengembalian kembali[200];

//procedure dan fungsi
void menu_utama(int *menu)
{
     system("cls");
     cout<<"Menu Perpustakaan"<<endl;
     cout<<"=========================="<<endl;
     cout<<"1. Buku"<<endl;
     cout<<"2. Peminjaman"<<endl;
     cout<<"3. Pengembalian"<<endl;
     cout<<"4. Keluar"<<endl;
     cout<<"=========================="<<endl;
     cout<<endl;
     cout<<"Pilih menu : ";
     cin>>*menu;
}

void menu_buku(int *menu_bk)
{
     system("cls");
     cout<<"Menu Buku"<<endl;
     cout<<"=========================="<<endl;
     cout<<"1. Tambah Buku Baru"<<endl;
     cout<<"2. Daftar Buku"<<endl;
     cout<<"3. Kembali ke menu utama"<<endl;
     cout<<"=========================="<<endl;
     cout<<endl;
     cout<<"Pilih menu : ";
     cin>>*menu_bk;
}

void menu_peminjaman(int *menu_pinjam)
{
     system("cls");
     cout<<"Menu Peminjaman"<<endl;
     cout<<"=========================="<<endl;
     cout<<"1. Peminjaman Baru"<<endl;
     cout<<"2. Daftar Peminjaman"<<endl;
     cout<<"3. Kembali ke menu utama"<<endl;
     cout<<"=========================="<<endl;
     cout<<endl;
     cout<<"Pilih menu : ";
     cin>>*menu_pinjam;
}

void menu_pengembalian(int *menu_kembali)
{
     system("cls");
     cout<<"Menu Pengembalian"<<endl;
     cout<<"=========================="<<endl;
     cout<<"1. Pengembalian Buku"<<endl;
     cout<<"2. Daftar Pengembalian"<<endl;
     cout<<"3. Kembali ke menu utama"<<endl;
     cout<<"=========================="<<endl;
     cout<<endl;
     cout<<"Pilih menu : ";
     cin>>*menu_kembali;
}

void gotoxy(int x, int y)
{
     HANDLE hConsoleOutput;
     COORD coordinate;
     coordinate.X=x;
     coordinate.Y=y;
     hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput,coordinate);
}

void tampil_data_buku(buku bk[100])
{ 
    if(b_array == 0)
    {
        cout<<"Data tidak ditemukan!";
        getch();
    } else { 
        system("cls");
        cout<<"Daftar Buku"<<endl;
        cout<<"=============================================================================="<<endl;
        cout<<"   Kode  |      Judul       |     Pengarang    |    Penerbit     |    Stok    ";
        cout<<endl;
        cout<<"=============================================================================="<<endl;
        for(i = 0; i < b_array; i++)
        {
            gotoxy(1,i+4);cout<<"        |                  |                  |                 |            ";
            gotoxy(3,i+4);cout<<bk[i].kode;
            gotoxy(11,i+4);cout<<bk[i].judul;
            gotoxy(30,i+4);cout<<bk[i].pengarang;
            gotoxy(50,i+4);cout<<bk[i].penerbit;
            gotoxy(70,i+4);cout<<bk[i].stok;     
        }
        cout<<endl<<"=============================================================================="<<endl;
    }
}

void input_data_buku(buku bk[100], int *b_array)
{   
    int jml_buku;
    int j = *b_array;
    
    cout<<"Masukkan Jumlah Buku : ";
    cin>>jml_buku;
    *b_array = *b_array + jml_buku;
    
    for(i = j; i < *b_array; i++)
    {
        cout<<"Data Buku ke-"<<i+1<<endl;
        cout<<"=========================="<<endl;
        cout<<"Kode           = "<<i+1<<endl;
        bk[i].kode = i+1;
        cout<<"Judul          = ";
        fflush(stdin);
        cin.get(bk[i].judul,30);
        cout<<"Pengarang      = ";
        fflush(stdin);
        cin.get(bk[i].pengarang,30);
        cout<<"Penerbit       = ";
        fflush(stdin);
        cin.get(bk[i].penerbit,30);
        cout<<"Stok           = ";
        cin>>bk[i].stok;
        cout<<"=========================="<<endl;
        cout<<endl;   
    }
}

void tampil_data_pinjam(peminjaman pinjam[3], int p_array)
{   
    if(p_array == 0)
    {
        cout<<"Data tidak ditemukan!";
        getch();
    } else {     
        system("cls");
        cout<<"Daftar Peminjaman"<<endl;
        cout<<"================================================================================================"<<endl;
        cout<<"  Kode  |          Nama          |     Alamat     | Kode Buku |     Judul Buku     |  Tanggal  |";
        cout<<endl;
        cout<<"================================================================================================"<<endl;
        for(i = 0; i < p_array; i++)
        {
            gotoxy(3,i+4);cout<<pinjam[i].kode_peminjaman;
            gotoxy(11,i+4);cout<<pinjam[i].nama_peminjam;
            gotoxy(37,i+4);cout<<pinjam[i].alamat_peminjam;
            gotoxy(56,i+4);cout<<pinjam[i].kode_buku;
            gotoxy(65,i+4);cout<<pinjam[i].judul_buku;
            gotoxy(85,i+4);cout<<pinjam[i].tgl_pinjam.tgl<<"/"<<pinjam[i].tgl_pinjam.bln<<"/"<<pinjam[i].tgl_pinjam.thn;
            gotoxy(3,i+4);cout<<endl;     
        }
        cout<<"================================================================================================"<<endl;
    }
}

void pinjam_baru(int b_array, peminjaman pinjam[3], buku bk[3], int *p_array)
{
    ketemu = false; 
    
    awal1:
    if(b_array == 0)
    {
        cout<<"Tidak ada buku yang dapat anda pinjam!"<<endl;      
        getch();
    } else {
        tampil_data_buku(bk);   
        cout<<endl;
        cout<<"Kode buku yang akan dipinjam : ";
        cin>>kode_cari;
        
        for(i = 0; i < b_array; i++)
        {
            if(kode_cari == bk[i].kode)
            {
                ketemu = true;
                break;
            }     
        }
        if(ketemu == true)
        {   
            while (bk[i].stok < 1)
            {
                system("cls");
                cout<<"Stok buku yang anda pilih tidak tersedia! Silakan pilih kembali!"<<endl;
                getch();
                system("cls");
                tampil_data_buku(bk);
                cout<<endl;
                cout<<"Kode buku yang akan dipinjam : ";
                cin>>kode_cari;
                
                for(i = 0; i < b_array; i++)
                {
                    if(kode_cari == bk[i].kode)
                    {
                        ketemu = true;
                        break;
                    }     
                }
                
                if(b_array == 1)
                {
                    cout<<"Tidak ada buku yang dapat anda pinjam!"<<endl;
                    cout<<"Tekan sembarang tombol untuk kembali ke menu utama";
                    getch();
                    menu_utama(&menu);       
                }
                
            }
            system("cls");
            cout<<"Buku yang dipilih : "<<endl;
            cout<<"=============================================================================="<<endl;
            cout<<"   Kode  |      Judul       |     Pengarang    |    Penerbit     |    Stok    "<<endl;
            cout<<"=============================================================================="<<endl;
            cout<<"         |                  |                  |                 |            ";
            gotoxy(3,4);cout<<bk[i].kode;
            gotoxy(11,4);cout<<bk[i].judul;
            gotoxy(30,4);cout<<bk[i].pengarang;
            gotoxy(50,4);cout<<bk[i].penerbit;
            gotoxy(70,4);cout<<bk[i].stok;
            cout<<endl;     
            cout<<"=============================================================================="<<endl;           
        } else {
            cout<<endl;   
            cout<<"Data tidak ditemukan";
            getch();
            goto awal1;
        } 
        
        cout<<endl;
        cout<<"Peminjaman"<<endl;
        cout<<"============================================="<<endl;
        cout<<"Kode Peminjaman    : "<<*p_array+1<<endl;;
        pinjam[*p_array].kode_peminjaman = *p_array+1;
        cout<<"Nama Peminjam      : ";
        fflush(stdin);
        cin.get(pinjam[*p_array].nama_peminjam, 30);
        cout<<"Alamat Peminjam    : ";
        fflush(stdin);
        cin.get(pinjam[*p_array].alamat_peminjam, 30);
        cout<<"Kode Buku          : "<<bk[i].kode<<endl;
        pinjam[*p_array].kode_buku = bk[i].kode;
        cout<<"Judul Buku         : "<<bk[i].judul<<endl;
        strcpy(pinjam[*p_array].judul_buku,bk[i].judul);
        cout<<"Tanggal Peminjaman : ";
        cin>>pinjam[*p_array].tgl_pinjam.tgl;
        cout<<"Bulan Peminjaman   : ";
        cin>>pinjam[*p_array].tgl_pinjam.bln;
        cout<<"Tahun Peminjaman   : ";
        cin>>pinjam[*p_array].tgl_pinjam.thn;
        bk[i].stok = bk[i].stok - 1;
        *p_array = *p_array + 1;
    }
}

void tampil_data_kembali(pengembalian kembali[3], int k_array)
{  
    if(k_array == 0)
    {
        cout<<"Data tidak ditemukan!";
        getch();       
    } else {
        system("cls");
        cout<<"Daftar Pengembalian"<<endl;
        cout<<"==================================================================================================================="<<endl;
        cout<<"   Kode  |          Nama          |     Alamat     | Kode Buku |     Judul Buku     |  Tanggal  |  Lama  |  Denda  "<<endl;
        cout<<"==================================================================================================================="<<endl;
        for(i = 0; i < k_array; i++)
        {
            gotoxy(4,i+4);cout<<kembali[i].kode_peminjaman;
            gotoxy(12,i+4);cout<<kembali[i].nama_peminjam;
            gotoxy(38,i+4);cout<<kembali[i].alamat_peminjam;
            gotoxy(58,i+4);cout<<kembali[i].kode_buku;
            gotoxy(67,i+4);cout<<kembali[i].judul_buku;
            gotoxy(86,i+4);cout<<kembali[i].tgl_kembali.tgl<<"/"<<kembali[i].tgl_kembali.bln<<"/"<<kembali[i].tgl_kembali.thn;
            gotoxy(101,i+4);cout<<kembali[i].lama;
            gotoxy(108,i+4);cout<<kembali[i].denda;
            cout<<endl;     
        }
        cout<<"==================================================================================================================="<<endl;
    }    
}

void kembali_baru(buku bk[3], peminjaman pinjam[3], pengembalian kembali[3], int *k_array, int *p_array)
{
    int t1,t2,t3,j;
    ketemu = false; 
    
    awal2:
    if(*p_array == 0)
    {
        cout<<"Tidak ada data peminjaman!"<<endl;
        getch();       
    } else {
        tampil_data_pinjam(pinjam,*p_array);
        cout<<endl;
        cout<<"Kode peminjaman yang akan di proses : ";
        cin>>kode_cari;
        
        //mencari data peminjaman
        for(i = 0; i < *p_array; i++)
        {
            if(kode_cari == pinjam[i].kode_peminjaman)
            {
                ketemu = true;
                break;
            }     
        }
        if(ketemu == true)
        {
            system("cls");
            cout<<"Data yang dipilih : "<<endl;
            cout<<"================================================================================================"<<endl;
            cout<<"  Kode  |          Nama          |     Alamat     | Kode Buku |     Judul Buku     |  Tanggal  |"<<endl;
            cout<<"================================================================================================"<<endl;
            cout<<"        |                        |                |           |                    |           |";
            gotoxy(3,4);cout<<pinjam[i].kode_peminjaman;
            gotoxy(11,4);cout<<pinjam[i].nama_peminjam;
            gotoxy(37,4);cout<<pinjam[i].alamat_peminjam;
            gotoxy(56,4);cout<<pinjam[i].kode_buku;
            gotoxy(65,4);cout<<pinjam[i].judul_buku;
            gotoxy(85,4);cout<<pinjam[i].tgl_pinjam.tgl<<"/"<<pinjam[i].tgl_pinjam.bln<<"/"<<pinjam[i].tgl_pinjam.thn<<endl;
            cout<<"================================================================================================"<<endl;       
        } else {
            cout<<endl;      
            cout<<"Data tidak ditemukan";
            getch();
            goto awal2;
        }
        
        //mencari data buku
        ketemu = false;
        for(j = 0; j < *p_array; j++)
        {
            if(pinjam[i].kode_peminjaman = bk[i].kode)
            {
                ketemu = true;
                break;
            }     
        } 
        
        cout<<endl;
        cout<<"Pengembalian"<<endl;
        cout<<"============================================="<<endl;
        cout<<"Kode Peminjaman  : "<<pinjam[i].kode_peminjaman<<endl;
        kembali[*k_array].kode_peminjaman = pinjam[i].kode_peminjaman;
        cout<<"Nama Peminjam    : "<<pinjam[i].nama_peminjam<<endl;
        strcpy(kembali[*k_array].nama_peminjam,pinjam[i].nama_peminjam);
        cout<<"Alamat Peminjam  : "<<pinjam[i].alamat_peminjam<<endl;
        strcpy(kembali[*k_array].alamat_peminjam,pinjam[i].alamat_peminjam);
        cout<<"Kode Buku        : "<<pinjam[i].kode_buku<<endl;
        kembali[*k_array].kode_buku = pinjam[i].kode_buku;
        cout<<"Judul Buku       : "<<pinjam[i].judul_buku<<endl;
        strcpy(kembali[*k_array].judul_buku,pinjam[i].judul_buku);
        cout<<"Tanggal Kembali  : ";
        cin>>kembali[*k_array].tgl_kembali.tgl;
        cout<<"Bulan Peminjaman : ";
        cin>>kembali[*k_array].tgl_kembali.bln;
        cout<<"Tahun Peminjaman : ";
        cin>>kembali[*k_array].tgl_kembali.thn;
        
        //menghitung lama
        t1=abs((kembali[*k_array].tgl_kembali.thn-pinjam[i].tgl_pinjam.thn)*365);
        t2=abs((kembali[*k_array].tgl_kembali.bln-pinjam[i].tgl_pinjam.bln)*30);
        t3=abs((kembali[*k_array].tgl_kembali.tgl-pinjam[i].tgl_pinjam.tgl));
        
        kembali[*k_array].lama = t1+t2+t3;
        cout<<"Lama Peminjaman  : "<<kembali[*k_array].lama<<" Hari"<<endl;
        
        if(kembali[*k_array].lama > 3)
        {
            kembali[*k_array].denda = (kembali[*k_array].lama - 3) * 1000;                      
        } else {
            kembali[*k_array].denda = 0;
        }
        cout<<"Denda            : "<<kembali[*k_array].denda<<endl;
        
        //menghapus data pengembalian
        for(j = i; j < *p_array; j++)
        {
            pinjam[i].kode_peminjaman = pinjam[i+1].kode_peminjaman;
            strcpy(pinjam[i].nama_peminjam,pinjam[i+1].nama_peminjam);
            strcpy(pinjam[i].alamat_peminjam,pinjam[i+1].alamat_peminjam);
            pinjam[i].kode_buku = pinjam[i+1].kode_buku;
            strcpy(pinjam[i].judul_buku,pinjam[i+1].judul_buku);
            pinjam[i].tgl_pinjam.tgl = pinjam[i+1].tgl_pinjam.tgl;
            pinjam[i].tgl_pinjam.bln = pinjam[i+1].tgl_pinjam.bln;
            pinjam[i].tgl_pinjam.thn = pinjam[i+1].tgl_pinjam.thn;  
        }
        //mengurangi data peminjaman
        *p_array = *p_array - 1;
        //menambahkan stok buku
        bk[i].stok = bk[i].stok + 1;
        //menambah data pengembalian
        *k_array = *k_array + 1;
    }
}

//fungsi utama
int main(int argc, char *argv[])
{
    do
    {
        menu_utama(&menu);
        switch(menu)
        {
            case 1:
                 do
                 {
                     menu_buku(&menu_bk);
                     switch(menu_bk)
                     {
                         case 1:
                              system("cls");
                              input_data_buku(bk,&b_array);
                              cout<<endl;
                              cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                              getch();
                              break;
                         case 2:
                              system("cls");
                              tampil_data_buku(bk);
                              cout<<endl;
                              cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                              getch();
                              break;
                         case 3:
                              break;
                         default:
                              cout<<"Menu yang anda pilih tidak valid!";
                              getch();       
                     }
                 }while(menu_bk != 3);
                 break;
            case 2:
                 do
                 {
                     menu_peminjaman(&menu_pinjam);
                     switch(menu_pinjam)
                     {
                         case 1:
                              system("cls");
                              pinjam_baru(b_array,pinjam,bk,&p_array);
                              cout<<endl;
                              cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                              getch();
                              break;
                         case 2:
                              system("cls");
                              tampil_data_pinjam(pinjam,p_array);
                              cout<<endl;
                              cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                              getch();
                              break;
                         case 3:
                              break;
                         default:
                              cout<<"Menu yang anda pilih tidak valid!";
                              getch();       
                     }
                 }while(menu_pinjam != 3);
                 break;
            case 3:
                 do
                 {
                     menu_pengembalian(&menu_kembali);
                     switch(menu_kembali)
                     {
                         case 1:
                              system("cls");
                              kembali_baru(bk,pinjam,kembali,&k_array,&p_array);
                              cout<<endl;
                              cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                              getch();
                              break;
                         case 2:
                              system("cls");
                              tampil_data_kembali(kembali,k_array);
                              cout<<endl;
                              cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                              getch();
                              break;
                         case 3:
                              break;
                         default:
                              cout<<"Menu yang anda pilih tidak valid!";
                              getch();       
                     }
                 }while(menu_kembali != 3);
                 break;
            case 4:
                 break;
            default:
                 cout<<"Menu yang anda pilih tidak valid!";
                 getch();       
        }     
    }while(menu != 4);
    return EXIT_SUCCESS;
}
