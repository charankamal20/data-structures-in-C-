#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int INF = INT_MAX;

int multistageGraph(int n, int m, vector<vector<int>> &graph,
                    vector<int> &costs, int vertex) {
  // Base case: if we're at the last vertex, return zero.
  if (vertex == n) {
    return 0;
  }

  // Initialize the minimum cost to INF.
  int minCost = INF;

  // Consider all vertices reachable from the current vertex in the next stage.
  for (int i = vertex + 1; i <= min(vertex + m, n); i++) {
    // Compute the cost to reach vertex i from the current vertex.
    int cost = graph[vertex][i] + costs[i];

    // Recursively compute the minimum cost to reach the end of the graph from
    // vertex i.
    int nextCost = multistageGraph(n, m, graph, costs, i);

    // Update the minimum cost if the current cost plus the next cost is less
    // than the current minimum.
    if (cost + nextCost < minCost) {
      minCost = cost + nextCost;
    }
  }

  // Return the minimum cost to reach the end of the graph from the current
  // vertex.
  return minCost;
}

int main() {
  int n = 12; // Number of vertices
  int m = 3;  // Number of stages

  // Initialize the graph with INF values.
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

  // Define the edges between vertices.
  graph[1][2] = 9;
  graph[1][3] = 7;
  graph[1][4] = 3;
  graph[1][5] = 2;
  graph[2][6] = 4;
  graph[2][7] = 2;
  graph[2][8] = 1;
  graph[3][6] = 2;
  graph[3][7] = 7;
  graph[4][8] = 11;
  graph[5][8] = 8;
  graph[5][7] = 11;
  graph[6][9] = 6;
  graph[6][10] = 5;
  graph[7][9] = 4;
  graph[7][10] = 3;
  graph[8][10] = 5;
  graph[8][11] = 6;
  graph[9][12] = 4;
  graph[10][12] = 3;
  graph[11][12] = 5;

  // Define the costs to reach each vertex.
  vector<int> costs(n + 1, 0);

  // Call the multistageGraph function to compute the minimum cost.
  int minCost = multistageGraph(n, m, graph, costs, 1);

  // Output the minimum cost.
  cout << "Minimum cost to reach vertex 1: " << minCost << endl;

  return 0;
}
