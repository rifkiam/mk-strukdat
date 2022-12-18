#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n, m, p, x, y, a, b, c;
int g[N][N], distancee[N][N], vis[N];

int bfs() {
    queue<int> q;
    q.push(1);
    distancee[1][1] = 0;
    vis[1] = 1;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (g[t][i] && !vis[i] && (t != a || i != b) && (t != b || i != c) && (t != c || i != a)) {
                q.push(i);
                distancee[i][1] = distancee[t][1] + 1;
                vis[i] = 1;
            }
        }
    }

    return distancee[n][1];
}

int main() {
    cin >> n >> m >> p;

    while (m--) {
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }

    while (p--) {
        cin >> a >> b >> c;
        g[b][a] = 0;
        g[c][b] = 0;
    }

    int res = bfs();
    if (res == 0) {
        cout << "-1" << endl;
        return 0;
    }

    int minDist = N;
    vector<int> path;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        memset(distancee, 0, sizeof distancee);
        vis[i] = 1;
        distancee[i][1] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (int j = 1; j <= n; j++) {
                if (g[t][j] && !vis[j] && (t != a || j != b) && (t != b || j != c) && (t != c || j != a)) {
                    q.push(j);
                    distancee[j][1] = distancee[t][1] + 1;
                    vis[j] = 1;
                }
            }
        }

        if (distancee[n][1] && distancee[n][1] < minDist) {
            minDist = distancee[n][1];
            path.clear();
            path.push_back(i);
        }
        else if (distancee[n][1] == minDist) {
            path.push_back(i);
        }
    }

    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }

    return 0;
}