#include <iostream>
using namespace std;

int main() 
{
    string nama = "Rifqi";
    string* ptrNama = &nama;
    cout << "nama " << nama << endl;
    cout << "&nama " << &nama << endl;
    cout << "*ptrNama " << *ptrNama << endl;
    cout << "ptrNama " << ptrNama << endl;
    
    return 0;
}