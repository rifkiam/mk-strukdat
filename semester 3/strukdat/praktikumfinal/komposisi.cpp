#include <bits/stdc++.h>
using namespace std;

// int arr[1000];
vector<int> arr;
vector<double> rata;
int ratarata;

void process(int komp)
{
    arr.push_back(komp);
}

void gass()
{
    double temp = 0;
    ratarata = 0;
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); ++it)
    {
        ratarata++;
        temp += *it;
    }
    rata.push_back(temp/arr.size());

    cout << setprecision(2) << fixed << temp / (arr.size());
    cout << endl;
}

int main()
{
    int a;
    double b;
    cin >> a;
    cin >> b;

    double res = 0;
    double final = 0;
    for (int i = 0; i < a; i++)
    {
        string tempstr;
        int tempint;

        cin >> tempstr;

        if (tempstr == "GASS")
        {
            gass();
        }
        else
        {
            cin >> tempint;
            process(tempint);
        }
    }

    vector<double>::iterator it;
    // int p = 0;
    for (it = rata.begin(); it != rata.end(); ++it)
    {
        res += *it;
    }

    final = res/(rata.size());
    cout << final << " ";

    if ((b * 0.5) < final && (b * 1.5) >= final)
    {
        cout << "AMAN";
    }
    else
    {
        cout << "LOH";
    }

    return 0;
}