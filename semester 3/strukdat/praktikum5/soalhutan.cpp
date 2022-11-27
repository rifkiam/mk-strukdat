#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int> m;

string cek() {
    map <string, int> ::iterator itr;
    int i = m.size();
    bool res = false;
    for (itr = m.begin(); itr != m.end(); itr++) 
    {
        if (itr -> second > 0) res = true;
    }
    if (!res && i <= 1) 
    {
        return "tidak keduanya";
    }
    if (!res && i > 1) 
    {
        return "heterogen";
    }
    if (res) 
    {
        if (m.size() > 1) {
            return "keduanya";
        } else {
            return "homogen";
        }
    }
    return "test";
}

int main() {
    int N;
    cin >> N;

    while(N--) {
        string a, temp;
        cin >> a >> temp;
        map<string,int>::iterator it;
        it = m.find(temp);

        if (a == "insert") 
        {
            if (it == m.end()) 
                m.insert({temp, 0});
            else 
                it -> second++;
        } 
        else 
        {
            if (it -> second > 0) 
            {
                it -> second--;
            } 
            else 
            {
                m.erase(temp);
            }
        }
        cout << cek() << endl;
    }
    return 0;
}