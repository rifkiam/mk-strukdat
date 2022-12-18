#include <iostream>

using namespace std;

bool cts(int a, int b, int c, int n, int computers[]) {
  return computers[a - 1] == b && computers[b - 1] == c && computers[c - 1] == a;
}

int main() {
  int n;
  cin >> n;

  int computers[n];
  for (int i = 0; i < n; i++) {
    cin >> computers[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (cts(i, j, k, n, computers)) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  cout << "NO";
  return 0;
}