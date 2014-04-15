// Simple O(V E) solution to 'Sensor Network'.
// David Garcia Soriano.
#include <algorithm>
#include <cstdio>
#include <list>
#include <vector>
using namespace std;

const int infinity = 1000000000;
const int maxn = 350;

struct Edge {
  int a, b, cost;
  Edge(int aa, int bb, int c) : a(aa), b(bb), cost(c) {}
  bool operator<(const Edge &e) const { return cost < e.cost; }
  int endpoint(int from) { return a + b - from; }
};

typedef list<Edge>::iterator EdgePtr;

// Adjacency list of the current forest
vector<EdgePtr> adj[maxn];
EdgePtr last_edge[maxn];
bool visited[maxn];

void dfs(int a, int b) {
  visited[a] = true;
  if (a != b)
    for (vector<EdgePtr>::iterator it = adj[a].begin(); it != adj[a].end(); ++it) {
      int v = (*it)->endpoint(a);
      if (!visited[v]) {
        last_edge[v] = *it;
        dfs(v, b);
      }
    }
}

int main() {
  int n, numedges;
  while (scanf("%i", &n), n) {
    scanf("%i", &numedges);
    vector<Edge> all_edges;
    for (int i = 0; i < numedges; ++i) {
      int a, b, cost;
      scanf("%i%i%i", &a, &b, &cost);
      all_edges.push_back(Edge(a, b, cost)); // a != b
    }

    sort(all_edges.begin(), all_edges.end());
    list<Edge> current; // list of edges in current spanning forest
    int ret = infinity, 
        intree = 1;     // 1 + number of edges in the current forest
    for (vector<Edge>::iterator e = all_edges.begin(); e != all_edges.end(); ++e) {
      // Build adjacency list
      for (int i = 0; i < n; ++i) adj[i].clear();
      for (EdgePtr it = current.begin(); it != current.end(); ++it) {
        adj[it->a].push_back(it);
        adj[it->b].push_back(it);
      }

      // Find the path between e->a and e->b in forest 'current',
      // or determine that no such path exists
      fill(&visited[0], &visited[n], false);
      dfs(e->a, e->b);
      if (!visited[e->b]) {
        ++intree;
        current.push_back(*e);
      } else {
        // Need to remove the lightest edge in the path
        int v = e->b, bestv = -1, cost;
        while (v != e->a) {
          if (bestv < 0 || last_edge[v]->cost < cost) {
            cost = last_edge[v]->cost;
            bestv = v;
          }
          v = last_edge[v]->endpoint(v);
        }
        current.erase(last_edge[bestv]);
        current.push_back(*e);
      }

      if (intree == n) 
        ret = min(ret, current.back().cost - current.front().cost);
    }
    printf("%i\n", ret);
  }
  return 0;
}
