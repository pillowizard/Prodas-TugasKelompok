#include <cstdlib>
#include <iostream>

using namespace std;

int faktorial(int n);

int main()
{
    int n, hasil;
    cout<<"FUNGSI FAKTORIAL"<<endl;
    cout<<"Masukan nilai = ";
    cin>>n;
    hasil = faktorial(n);
    cout<<"Hasil faktorial = "<<hasil<<endl;
   
    system("PAUSE");
    return EXIT_SUCCESS;
}

int faktorial(int n) {
    if(n==1 || n==0){
          return 1;
    } else {
          return n*faktorial(n-1);
    }
}
