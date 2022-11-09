#include <iostream>
using namespace std;

struct characters
{
    int id;
    string nama;
    float hp;
    int stats[2];
};

int main() {
    characters playables[20];

    for (int i = 0; i < 20; i++)
    {
        playables[i].id = (i+1);
        cout << "Character id: " << playables[i].id << endl;

        cout << "Insert character's name: ";
        cin >> playables[i].nama;
        cout << "Insert character's amount of hp: ";
        cin >> playables[i].hp;
        cout << "Input 2 stats (ATK DEF)" << endl;
        for (int j = 0; j < 2; j++)
        {
            cin >> playables[i].stats[j];
        }
    }

    cout << "Characters you have created are: " << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "Character id: " << playables[i].id << endl;
        cout << "Character name: " << playables[i].nama << endl;
        cout << "Character hp amount: " << playables[i].hp << endl;
        cout << "Character basic stats: " << playables[i].stats[0] << " " << playables[i].stats[1] << endl << endl;
    }

    return 0;
}


