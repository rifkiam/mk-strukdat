#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    list<bool> *visitedNode;
    // vector<list<int>> l;

    public:
    Graph(int len)
    {
        V = len;
        l = new list<int> [V];
    }

    // void addEdge(int x, int y) // for bi-directed graphs
    // {
    //     l[x].push_back(y);
    //     l[y].push_back(x);
    // }

    void addEdge(int from, int to) // for directed graphs
    {
        if(l[from].empty()) l[from].push_back(from);
        if(l[to].empty()) l[to].push_back(to);
        l[from].push_back(to);
    }

    void showGraph(){
        for (int i = 0; i <= V; i++)
        {
            list<int>::iterator it;
            for(it = l[i].begin(); it != l[i].end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    void BFS(int startVertex) {
        *visitedNode = new list<bool>[V];
        for (int i = 0; i < V; i++)
        {
            visitedNode[i] = false;
        }

        list<int> queue;

        visitedNode[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;

        while (!queue.empty()) {
            int currVertex = queue.front();
            cout << "Visited " << currVertex << " ";
            queue.pop_front();

            for (i = l[currVertex].begin(); i != l[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visitedNode[adjVertex]) {
                visitedNode[adjVertex] = true;
                queue.push_back(adjVertex);
            }
            }
        }
    }
};

int main() {
    Graph coba(5);
    coba.addEdge(4, 2);
    coba.addEdge(4, 3);
    coba.addEdge(2, 1);
    coba.addEdge(2, 3);
    coba.addEdge(1, 3);
    coba.addEdge(0, 1);

    coba.showGraph();

    coba.BFS(4);
    return 0;
}