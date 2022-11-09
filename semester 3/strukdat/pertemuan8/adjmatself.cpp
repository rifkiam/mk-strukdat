#include <iostream>
using namespace std;

const int nup = 5;

void init(int arr[][nup]) {
    for (int i = 0; i < nup; i++)
    {
        for (int j = 0; j < nup; j++)
        {
            arr[i][j] = 0;
            arr[j][i] = 0;

        }
    }
}

int main() {
    return 0;
}