#include <iostream>
using namespace std;

int n[100];
int tembakan = 0;

/*int deleteElement(int arr[], int n, int x)
{
    // Search x in array
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
            break;
    
    // If x found in array
    if (i < n)
    {
        // reduce size of array and move all
        // elements on space ahead
        n = n - 1;
        for (int j=i; j<n; j++)
            arr[j] = arr[j+1];
    }
    
    return n;
}*/

void solve(int k) {
    int i = 0;
    int j;
    for (i; i < k; i++)
    {
        if (n[i] == 0)
        {
            tembakan - 1;
            continue;
        }

        for (j = i + 1; j < k; j++)
        {
            if (n[j] == n[i] - 1)
            {
                n[i] = 0;
                i = j;
            }
        }
        tembakan++;
    }
    cout << tembakan;
}

int main() {
    int i, j;
    int T;
    cin >> T;
    
    for (j = 0; j < T; j++)
    {
        for (i = 0; i < 100; i++) //BINGUNG GAADA BATAS
        {
            cin >> n[i];
        }
        solve(i);
        cout << endl;
    }
    return 0;
}
