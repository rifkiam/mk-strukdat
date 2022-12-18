#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}

int main() {
    vector<int> arr;

    while(true)
    {
        int val;
        cin >> val;
        if (val == 0)
        {
            break;
        }
        else
        {
            arr.push_back(val);
        }
    }

    remove(arr);
    vector<int>::iterator it;
    sort(arr.begin(), arr.end());
    for (it = arr.begin(); it != arr.end(); ++it)
    {
        cout << *it << endl;
    }
}