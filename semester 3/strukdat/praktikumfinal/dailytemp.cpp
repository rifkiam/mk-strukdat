#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        int hari = 0;
        bool nemu = false;
        int temparr[n] = {};
        for (int j = (i+1); j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temparr[hari] = arr[j];
                hari++;
                continue;
            }
            else if (arr[j] > arr[i])
            {
                temparr[hari] = arr[j];
                hari++;
                nemu = true;
                break;
            }
        }
        
        if (nemu == true)
        {
            cout << hari << " ";
            for (int k = 0; temparr[k] != 0; k++)
            {
                cout << temparr[k] << " ";
            }
            cout << endl;
        }
        
        else if (nemu == false)
        {
            cout << "letsgo!!" << endl;
        }
    }
    
}