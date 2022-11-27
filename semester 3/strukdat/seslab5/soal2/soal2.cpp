#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int counter;
    set<int> sset;
    cin >> counter;
    for (int i = 0; i < counter; ++i){
        int type, query;
        cin >> type >> query;
        switch (type){
            case 1:
                sset.insert(query);
                break;
            case 2:
                sset.erase(query);
                break;
            case 3:
                cout << (sset.find(query) == sset.end() ? "No" : "Yes") << endl;
                break;
        }
    }  
return 0;
}