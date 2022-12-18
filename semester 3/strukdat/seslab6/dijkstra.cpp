#include <bits/stdc++.h>

using namespace std;

#define infinite 1000000000

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int n, m, s;
    cin >> n >> m;

    vector<vii> adjList(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adjList[x - 1].push_back(ii(y - 1, w));
        adjList[y - 1].push_back(ii(x - 1, w));
    }

    cin >> s;
    s--;

    vi dist(n, infinite);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue;
        for (int j = 0; j < (int)adjList[u].size(); j++) {
            ii v = adjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != s)
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}