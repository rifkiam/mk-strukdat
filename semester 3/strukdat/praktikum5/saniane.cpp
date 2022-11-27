#include <bits/stdc++.h>

using namespace std;

int jalan[100001];

int main() {
    int n;
    cin >> n;
    int h;
    cin >> h;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        jalan[i] = temp;
    }

    for (int i = 0; i <= n; i++)
    {
        if (h == jalan[i])
        {
            
            flag = true;
            break;
        }
        else
        {
            continue;
        }
    }

    if (flag == false)
    {
        cout << "Yah gagal";
    }
    
    else if (flag == true)
    {
        cout << "Berhasil, HORE!";
    }
    
}