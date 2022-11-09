#include <iostream>
#include <list>
using namespace std;

class Mahasiswa {
    public:
    void printName() {
        cout << "My name is " << Name << " NRP " << NRP << endl;
    }

    string getName() {
        return Name;
    }

    Mahasiswa(string Nama, string NoID) { //constructor
        Name = Nama;
        NRP = NoID;
    }

    private:
    string Name;
    string NRP;
};

class graph {
    public:
    graph(int len) {
        length = len;
    }

    void setNewLength(int len) {
        length = len;
    }
    
    private:
    int length;
};

int main() {
    Mahasiswa mhs1("Muhammad Ali", "1412047120");
    mhs1.printName();
    // cout << mhs1.getName();
    // list<int>* adj;
    // adj = new list<int>[5];
    // list<int> myList;
    // adj[0].push_back(1);
}