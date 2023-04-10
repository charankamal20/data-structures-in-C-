#include <bits/stdc++.h>
// This triplet contains all the data for a node, source / distance from source / destination node
using namespace std;

const int N = 1e5 + 10;
#define INF 1e9 + 10

// vector<pair<int, int>> graph[N];

int dijkstra(int source, int n, vector<pair<int, int>> Graph[N]) {

  vector<int> visited(N, 0);
  vector<int> distance(N, INF);
  set<pair<int,int>> nodes;

  nodes.insert({0, source});
  distance[source] = 0;

  while(nodes.size() > 0) {
    auto node = *nodes.begin();
    int v = node.second;
    int dist = node.first;
    nodes.erase(nodes.begin());
    if (visited[v] == 1) continue;
    visited[v] = 1;
    for ( auto child : Graph[v])  {
      int child_v = child.first;
      int weight = child.second;
      if(distance[v] + weight < distance[child_v])  {
        distance[child_v] = distance[v] + weight;
        nodes.insert({distance[child_v], child_v});
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++)  {
    if (distance[i] == INF) return -1;
    ans = max(ans, distance[i]);
  }

  return ans;
}

int createGraph(vector<vector<int>>& times, int n , int k) {
  vector<pair<int, int>> Graph[N];
  for (auto vec : times)  {
    Graph[vec[0]].push_back({vec[1], vec[2]});

  }

  return dijkstra(0, n, Graph);

}

int main(int argc, char *argv[]) {

  // vector<
  vector<pair<int, int>> graph[N];

  graph[1].push_back({2,10});
  graph[1].push_back({3,3});
  graph[2].push_back({4,2});
  graph[2].push_back({3,1});
  graph[3].push_back({4,2});
  graph[3].push_back({4,8});
  graph[3].push_back({5,2});
  graph[5].push_back({4,9});
  graph[4].push_back({5,7});

  cout << dijkstra(0,5, graph);

  return 0;
}