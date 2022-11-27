#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <array>
using namespace std;

int n;
string arrayNama[100001];

void check(string temp) {

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp == arrayNama[j])
            {
                cout << temp << "1";
                return;
            }
            else
            {
                cout << "OK";
                arrayNama[j] = temp;
                return;
            }
        }
    }
}


int main() {

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        check(temp);
        cout << endl;
    }
    return 0;
}
