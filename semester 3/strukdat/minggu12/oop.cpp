#include <iostream>
#include <list>
using namespace std;

class Mahasiswa
{
public:
    void printName()
    {
        cout << "My name is " << Name;
    }

    void setName()
    {
        cin >> Name;
    }

private:
    string Name;
};

int main()
{
    Mahasiswa mhs1;
    mhs1.setName();
    mhs1.printName();
}