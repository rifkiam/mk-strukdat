#include <iostream>
using namespace std;

string n[200];

void solve(int k) {
    int i = 0;
    for (i; i < k; i++)
    {
        if (n[i + 1] == n[i] - 1)
        {
            for (i; i <= 9; i++)
            {
                n[i] = n[i + 1];
            }
        cout << n;
        }
        else
        {
            break;
        }
    }
}

int main() {
    int i, j;
    int T;
    cin >> T;
    
    for (j = 0; j < T; j++)
    {
        for (i = 0; i < 5; i++)
        {
            cin >> n[i];
        }
        solve(i);
    }

    return 0;
}

/*cin >> pos;

    for (i = pos; i <= 9; i++)
    {
        arr[i] = arr[i + 1];
    }

    cout << " \n\nThe " << n-1 << " elements of the array, after deletion are : \n\n";
    for(i=0; i<n-1; i++)
    {
        cout << arr[i] << "  "; 
    }
             
    cout << "\n\n";

    return 0;
}*/