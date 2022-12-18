#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices;
    list<pair<int, int>> *adjMatrix;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void BFS(int startVertex);
    void showMatrix();
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjMatrix = new list<pair<int, int>>[vertices];
}

void Graph::addEdge(int src, int dest, int weight)
{
    adjMatrix[src].push_back(make_pair(dest, weight));
    adjMatrix[src].sort();
}

void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<pair<int, int>>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        // Fungsi memberhentikan BFS
        // if (currVertex == endVertex)
        // {
        // break;
        // }
        //
        // cout << "(V" << currVertex << ")";
        queue.pop_front();

        // for ( auto v : )
        // {
        //     /* code */
        // }

        for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
        {
            for (auto v : adjMatrix[currVertex])
            {
                cout << v.first << " ";
                cout << v.second << endl;
            }

            // int adjVertex = *i;
            // if (!visited[adjVertex])
            // {
            //     visited[adjVertex] = true;
            //     queue.push_back(adjVertex);
            // }
        }
    }
}

int main()
{
    Graph coba(4);

    coba.addEdge(0, 1, 2); // src, destination, weight
    coba.addEdge(0, 3, 1);
    coba.addEdge(1, 2, 5);
    coba.addEdge(1, 3, 2);

    coba.BFS(1);

    // Graph coba(20);
    // coba.addEdge(0, 1);
    // coba.addEdge(0, 3);
    // coba.addEdge(1, 2);
    // coba.addEdge(1, 3);
    // coba.addEdge(1, 4);
    // coba.addEdge(1, 5);
    // coba.addEdge(3, 6);
    // coba.addEdge(6, 7);
    // coba.addEdge(6, 8);
    // coba.addEdge(6, 8);
    // coba.addEdge(8, 9);
    // coba.addEdge(9, 10);
    // coba.addEdge(10, 9);
    // coba.addEdge(10, 11);
    // coba.addEdge(11, 10);
    // coba.addEdge(11, 15);
    // coba.addEdge(15, 11);
    // coba.addEdge(15, 14);
    // coba.addEdge(14, 12);
    // coba.addEdge(14, 15);
    // coba.addEdge(12, 8);
    // coba.addEdge(12, 13);
    // coba.addEdge(12, 14);
    // coba.addEdge(13, 16);
    // coba.addEdge(16, 17);
    // coba.addEdge(16, 19);
    // coba.addEdge(17, 16);
    // coba.addEdge(17, 18);
    // coba.addEdge(18, 17);
}