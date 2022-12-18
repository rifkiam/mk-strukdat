#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, m, x, y, w, ans;
vector<pair<int, pair<int, int>>> v;
int part[100];

int find(int x);
void join(int x, int y);

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        x--, y--;
        v.push_back({w, {x, y}});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) part[i] = i;
    for(int i = 0; i < m; i++)
    {
        w = v[i].first;
        x = v[i].second.first;
        y = v[i].second.second;
        if(find(x) != find(y))
        {
            ans += w;
            join(x, y);
        }
    }
    cout << ans << endl;
}

int find(int x)
{
    if(part[x] == x) return x;
    return part[x] = find(part[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    part[x] = y;
}