#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjLists;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex, int endVertex);
    void showList();
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
  adjLists[src].push_back(dest);
  // adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    if (currVertex == endVertex)
    {
      break;
    }
    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
    {
      int adjVertex = *i;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::showList()
{
  for (int i = 0; i < numVertices; i++)
  {
    cout << i << ": ";
    list<int>::iterator it;
      for(it = adjLists[i].begin(); it != adjLists[i].end(); ++it){
        cout << *it << " ";
      }
    cout << endl;
  }
}

int main()
{
  Graph coba(20);
  coba.addEdge(0, 1);
  coba.addEdge(0, 3);
  coba.addEdge(1, 2);
  coba.addEdge(1, 3);
  coba.addEdge(1, 4);
  coba.addEdge(1, 5);
  coba.addEdge(3, 6);
  coba.addEdge(6, 7);
  coba.addEdge(6, 8);
  coba.addEdge(6, 8);
  coba.addEdge(8, 9);
  coba.addEdge(9, 10);
  coba.addEdge(10, 9);
  coba.addEdge(10, 11);
  coba.addEdge(11, 10);
  coba.addEdge(11, 15);
  coba.addEdge(15, 11);
  coba.addEdge(15, 14);
  coba.addEdge(14, 12);
  coba.addEdge(14, 15);
  coba.addEdge(12, 8);
  coba.addEdge(12, 13);
  coba.addEdge(12, 14);
  coba.addEdge(13, 16);
  coba.addEdge(16, 17);
  coba.addEdge(16, 19);
  coba.addEdge(17, 16);
  coba.addEdge(17, 18);
  coba.addEdge(18, 17);

  // coba.BFS(0, 19);
  cout << endl;
  coba.showList();

  return 0;
}