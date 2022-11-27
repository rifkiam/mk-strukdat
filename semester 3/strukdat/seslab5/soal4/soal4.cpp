#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    map<string, int> stlmap;
    
    while (n--) {
        int t;
        cin >> t;
        
        string s;
        cin >> s;
        
        if (t == 1) {
            int a;
            cin >> a;
            
            stlmap[s] += a;
        } else if (t == 2) {
            stlmap[s] = 0;
        } else {
            cout << stlmap[s] << "\n";
        }
    }
    
    return 0;
}