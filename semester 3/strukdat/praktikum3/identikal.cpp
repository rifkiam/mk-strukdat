#include <iostream>
using  namespace std;

/* Node structure */

int main() {
    
    int x[100];
    int y[100];
    bool same;

    int n;
    while (cin >> n)
    {
        int i = 0;
        x[i] = n;
        i++;
    }

    int m;
    while (cin >> m)
    {
        int i = 0;
        y[i] = m;
        i++;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (x[i] == y[j])
            {
                same = true;
            } 
            else
            {
                same = false;
                break;
            };
        }
        cout << "True";
    }
    // cout << x;
    
    return 0;
}