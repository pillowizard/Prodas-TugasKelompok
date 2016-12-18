#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

//variable global
int i;
int j;
int x;
int y;
int t_pesanan;
int b_pesanan;

//fungsi gotoxy
void gotoxy(int x, int y)
{
     HANDLE hConsoleOutput;
     COORD coordinate;
     coordinate.X=x;
     coordinate.Y=y;
     hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput,coordinate);
}

void cetak_stok(int s_ayam, int s_bebek)
{
     cout<<"Stok tersedia : "<<endl;
     cout<<"- Ayam  = "<<s_ayam<<endl;
     cout<<"- Bebek = "<<s_bebek<<endl;
}

void pemesanan(int b_pesanan, int *t_pesanan, int p_ayam[], int p_bebek[], int *s_ayam, int *s_bebek, int c_ayam[], int c_bebek[])
{
     //variable bantuan k untuk menampung nilai t_pesanan awal
     int k = *t_pesanan;
     cout<<"Masukkan jumlah pembelian = ";
     cin>>b_pesanan;
     cout<<endl<<"Detail Pemesanan :"<<endl;
     *t_pesanan = *t_pesanan + b_pesanan;
     for(i = 0; i < b_pesanan; i++)
     { 
         //validasi apabila jumlah pesanan melebihi stok yang tersedia  
         do
         {    
              cout<<"Masukkan Jumlah Ayam ke-"<<i+1<<"  = ";
              cin>>p_ayam[i];
              cout<<"Masukkan Jumlah Bebek ke-"<<i+1<<" = ";
              cin>>p_bebek[i];
              if(p_ayam[i] > *s_ayam || p_bebek[i] > *s_bebek){
                    cout<<endl<<"Stok ayam atau bebek tidak mencukupi!"<<endl;
                    cetak_stok(*s_ayam,*s_bebek);
                    cout<<"Isi kembali jumlah pesanan!"<<endl;
              }              
         }while(p_ayam[i] > *s_ayam || p_bebek[i] > *s_bebek);
         //memperbarui jumlah stok yang ada
         *s_ayam = *s_ayam - p_ayam[i];
         *s_bebek = *s_bebek - p_bebek[i];
         //memperbarui urutan pesanan
         c_ayam[k+i] = p_ayam[i];
         c_bebek[k+i] = p_bebek[i];
     }
}

void cetak_pesanan(int t_pesanan, int c_ayam[], int c_bebek[])
{
     cout<<"-------------------------------------------------------"<<endl;
     cout<<"|  Nomor Pesanan  |   Jumlah Ayam   |   Jumlah Bebek  |"<<endl;
     cout<<"-------------------------------------------------------"<<endl;
     for(i = 0; i < t_pesanan; i++)
     {
           cout<<"|                 |                 |                 |"<<endl;
           gotoxy(9,i+3);cout<<i+1;
           gotoxy(28,i+3);cout<<c_ayam[i];
           gotoxy(45,i+3);cout<<c_bebek[i];
           cout<<endl;
     }
     cout<<"-------------------------------------------------------"<<endl;
} 

void menu_utama()
{
     system("cls");
     cout<<"Menu Resto Ayam"<<endl;
     cout<<"----------------------"<<endl;
     cout<<"1. Pemesanan"<<endl;
     cout<<"2. Cetak Semua Pesanan"<<endl;
     cout<<"3. Stok Ayam dan Bebek"<<endl;
     cout<<"4. Keluar"<<endl;
}

int main(int argc, char *argv[])
{
    int menu;
    int p_ayam[b_pesanan];
    int p_bebek[b_pesanan];
    int s_ayam = 50;
    int s_bebek = 50;
    int c_ayam[t_pesanan];
    int c_bebek[t_pesanan];
    
    do
    {
        menu_utama();
        cout<<"Masukkan menu pilihan = ";
        cin>>menu;
        switch(menu)
        {
               case 1:
                    system("cls");
                    pemesanan(b_pesanan,&t_pesanan,p_ayam,p_bebek,&s_ayam,&s_bebek,c_ayam,c_bebek);
                    cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                    getch();
                    break;
               case 2:
                    system("cls");
                    cetak_pesanan(t_pesanan,c_ayam,c_bebek);
                    cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                    getch();
                    break;
               case 3:
                    system("cls");
                    cetak_stok(s_ayam,s_bebek);
                    cout<<"Tekan sembarang tombol untuk kembali ke menu utama!";
                    getch();
                    break;
               case 4:
                    break;
               default:
                    cout<<"Menu yang anda pilih tidak valid!";
                    getch();       
        }
    }while(menu !=4);
    return EXIT_SUCCESS;
}
