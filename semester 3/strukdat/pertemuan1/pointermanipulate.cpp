#include <iostream>
using namespace std;

int main() 
{
    string nama = "Rifqi";
    string* ptrNama = &nama;
    cout << "nama " << nama << endl;
    cout << "&nama " << &nama << endl << endl;

    cout << "Manipulasi nama" << endl;
    *ptrNama = "Kiamu";
    cout << nama << endl;
    cout << &nama << endl;

    return 0;
}