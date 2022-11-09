#include <iostream>
using namespace std;

int main(){
    int x[] = {12, 45, 8, 5, 16};
    int j = sizeof(x)/sizeof(*x);
    int temp;
    for(int i = 0; i < j; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl << endl;

    for(int i = 0; i < j; i++) //for loop dengan batasan i kurang dari j untuk memeriksa semua kemungkinan angka untk disorting
    {
        int acak = 0; // penanda ada pengurutan itu atau tdk
        for(int h = 0; h < j-1; h++) //sorting dgn penukaran angka sederhana
        {
            if(x[h] > x[h+1])
            {
                cout << " tahap :  " << i + 1 << " : "; 
                temp = x[h];
                x[h] = x[h+1];
                x[h+1] = temp;
                for (int i = 0; i < j; i++) // 
                {
                    cout << x[i] << " " ;
                }
                cout << endl;
                acak++;
            }
        }

        if(acak == 0)
        {
            break;
        }
        // for(int a = 0; a < j; a++){
        //    cout << x[a] << " ";
        // }
        cout << endl;
   }
    //menunjukan hasil akhir
    cout << " hasil : ";
    for(int a = 0; a < j; a++)
    {
        cout << x[a] << " ";
    }
}