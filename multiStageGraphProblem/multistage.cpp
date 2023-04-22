#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int INF = INT_MAX;

int multistageGraph(int n, int m, vector<vector<int>> &graph,
                    vector<int> &costs) {
  // Create a 1D vector to store the minimum costs to reach each vertex.
  vector<int> minCosts(n + 1, INF);

  // The minimum cost to reach the last vertex is zero.
  minCosts[n] = 0;

  // Starting from the last vertex, compute the minimum cost to reach each
  // vertex.
  for (int i = n - 1; i >= 1; i--) {
    // Iterate over all vertices reachable from vertex i.
    for (int j = i + 1; j <= min(i + m, n); j++) {
      // Compute the cost to reach vertex j from vertex i.
      int cost = graph[i][j] + costs[j];

      // Update the minimum cost to reach vertex i if the cost to reach vertex j
      // plus the cost to reach vertex j is less than the current minimum cost.
      if (cost < minCosts[i]) {
        minCosts[i] = cost;
      }
    }
  }

  // Return the minimum cost to reach the first vertex.
  return minCosts[1];
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
  graph[4][9] = 10;
  graph[5][9] = 8;
  graph[6][10] = 6;
  graph[6][11] = 5;
  graph[7][10] = 4;
  graph[7][11] = 3;
  graph[8][11] = 5;
  graph[8][12] = 6;
  graph[9][11] = 4;
  graph[9][12] = 3;

  // Define the costs to reach each vertex.
  vector<int> costs(n + 1, 0);

  // Call the multistageGraph function to compute the minimum cost.
  int minCost = multistageGraph(n, m, graph, costs);

  // Output the minimum cost.
  cout << "Minimum cost to reach vertex 1: " << minCost << endl;

  return 0;
}
