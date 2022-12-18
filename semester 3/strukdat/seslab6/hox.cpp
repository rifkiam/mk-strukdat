#include <bits/stdc++.h>
using namespace std;

int a, b, c[100000], ans, sum;
vector<int> v[100000];
bool visited[100000];

int main()
{
    cin >> a >> b;
    for(int i = 0; i < a; i++) cin >> c[i];
    for(int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < a; i++)
    {
        if(visited[i])
        {
            continue;
        }
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int ab = 1e9;
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            ab = min(ab, c[now]);
            for(int x : v[now])
            {
                if(visited[x]) continue;
                q.push(x);
                visited[x] = true;
            }
        }
        ans += ab;
    }
    cout << ans << endl;
    return 0;
}