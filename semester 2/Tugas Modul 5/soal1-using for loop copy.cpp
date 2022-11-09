#include <iostream>
using namespace std;

int main() {

    int i = 0;
    int j = 0;
    int match, value;

    int n;
    cin >> n;

    int arrN[n];

    for(i; i < n; i++)
    {
        cin >> arrN[i];
    }

    int m;
    cin >> m;
    int arrQ[m];
    int ans[m];

    for(j; j < m; j++)
    {
        cin >> arrQ[j];
    }

    for(j = 0; j < m; j++)
    {
        match = 0;
        for(i = 0; i < n; i++)
        {
            if(arrQ[j] == arrN[i])
            {
                match = 1;
                ans[j] = i;
                break;
            }
        }
        if(match == 0)
        {
            ans[j] = -1;
        }
        cout << ans[j] << "\n";
    }

    return 0;
}