#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(false),cin.tie(NULL);

    long long n, a[5001];
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(a[a[a[i]]] == i){
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}