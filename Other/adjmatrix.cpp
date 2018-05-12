
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>

using namespace std;
#define MAX 100000


class AdjacencyMatrix
{
    private:
        int n;
        // int **adj;
        bool *visited;
        //int **predecessor;
        //int **w;
        //int minimum;
    public:
      int **adj;
        AdjacencyMatrix(int n)
        {
            this->n = n;
            visited = new bool [n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }

        void add_edge(int origin, int destin, int weight)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = weight;
            }
        }

        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"      ";
                cout<<endl<<endl<<endl;
            }
        }
};

int main()
{
    int nodes, max_edges, origin, destin, weight;
    bool undir;
    cout << "Enter 1 for undirected or 0 for directed";
    cin >>  undir;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout << "Enter edge and weight (-1 -1 to exit): ";
        cin >> origin >> destin >> weight;
        if((origin == -1) && (destin == -1))
            break;
            // continue;
        am.add_edge(origin, destin, weight);
        if (undir == 1) {
          am.add_edge(destin, origin, weight);
        }
    }
    am.display();

    std::cout << "yy" << '\n';
    int predecessor[nodes];
    int queue[nodes];
    int minimum;
    int i;
    int j;
    bool checked[nodes];
    int flag = 0;
    predecessor[0] = -1;
    queue[0] = 0;
    minimum = 0;

    for(i=0;i<nodes-1;i++)
    {
      std::cout << "ss" << '\n';
      predecessor[i] = -2;
      queue[i] = 2000; //2147483647
    }
    for(i=0;i<max_edges;i++)
    {
      if(flag > nodes)
      {
        break;
      }
      else
      {
        if(checked[i] == 1)
        {
          continue;
        }
        i = minimum;
        for(j=0;j<max_edges;j++)
        {
          if(am.adj[i][j] != 0)
          {
            predecessor[j] = i;
            queue[j] = min(queue[j],queue[i] + am.adj[i][j]);
            minimum = min(minimum,queue[j]);
          }
        }
        checked[i] = 1;
        flag++;
      }
    }

    cout << "Shortest paths :-" << endl;

    for(i=0;i < nodes ;i++)
    {
      cout<< i+1 << " - " << queue[i] << endl;
    }
    return 0;
}
