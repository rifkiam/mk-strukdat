#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int j = 0;
    int k = 0;
    cin >> n;

    int arr[n];
    int ganjil[n / 2];
    int genap[n / 2];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ganjil[j] = arr[i];
            j++;
        }
        else
        {
            genap[k] = arr[i];
            k++;
        }
    }
    
    for (int i = 0; i < (j); i++)
    {
        cout << ganjil[i] << " ";
    }
    for (int i = 0; i < (k); i++)
    {
        cout << genap[i] << " ";
    }

    return 0;
}