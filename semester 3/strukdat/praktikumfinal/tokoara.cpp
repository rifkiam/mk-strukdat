#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  int total_prize = 0;

  vector<int> receipts;

  for (int i = 0; i < n; i++) {
    int num_receipts;
    cin >> num_receipts;

    for (int j = 0; j < num_receipts; j++) {
      int transaksi;
      cin >> transaksi;
      
      receipts.push_back(transaksi);
    }

    sort(receipts.begin(), receipts.end());

    if (receipts.size() >= 2) {
      total_prize += receipts[receipts.size() - 1] - receipts[0];
      receipts.pop_back();
      receipts.erase(receipts.begin());
    }
  }

  // Cetak total hadiah
  cout << total_prize << endl;

  return 0;
}