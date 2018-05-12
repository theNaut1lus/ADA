/*Dijkstra's algorith on a graph represented using linked list*/

#define INFINITY 9999
#include <climits>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

using namespace std;

typedef struct node {
  struct node *next;
  int vertex, weight;
} node;

node *G[10]; // linked list
int n;
void readgraph();
void insert(int vi, int vj, int w);
void dijkstra(int startnode);

int main() {
  int u;
  readgraph();
  cout << "\nEnter the starting node: ";
  cin >> u;
  dijkstra(u);
}

void dijkstra(int startnode) {
  int distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  node *p;
  for (i = 0; i < n; i++) {
    distance[i] = INFINITY;
    pred[i] = startnode;
    visited[i] = 0;
  }
  distance[startnode] = 0;
  count = 0;
  while (count < n - 1) {
    mindistance = INFINITY;
    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;

        visited[nextnode] = 1;
        for (p = G[nextnode]; p != NULL; p = p->next)
          if (!visited[p->vertex])
            if (mindistance + p->weight < distance[p->vertex]) {
              distance[p->vertex] = mindistance + p->weight;
              pred[p->vertex] = nextnode;
            }
        count++;
      }

    for (i = 0; i < n; i++)
      if (i != startnode) {
        cout << "\n FOR = " << i;
        cout << "		\n Path = " << i;
        j = i;
        do {
          j = pred[j];
          cout << "<- " << j;
        } while (j != startnode);
      }
  }
}

  void readgraph() {
    int i, j;
    int adj[10][10];
    cout << "\nEnter no. of vertices :";
    cin >> n;
    cout << "\nEnter Adjacency matrix :\n";
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        cin >> adj[i][j];

    for (i = 0; i < n; i++)
      G[i] = NULL;

    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (adj[i][j] != 0)
          insert(i, j, adj[i][j]);
  }

  void insert(int vi, int vj, int w) {
    node *p, *q;
    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    q->weight = w;
    if (G[vi] == NULL)
      G[vi] = q;
    else {
      p = G[vi];
      while (p->next != NULL)
        p = p->next;
      p->next = q;
    }
  }
