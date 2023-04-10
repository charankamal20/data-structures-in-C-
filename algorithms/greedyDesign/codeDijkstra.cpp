#include <bits/stdc++.h>
#include <exception>

std::vector<std::vector<std::pair<int, int>>> graph;
// pair is destination , weight

#define INF 1e9 + 10

void dijkstra(int source) {

  std::vector<bool> visited(graph.size(), false);
  std::vector<int> distance(graph.size(), INF);
  std::set<std::pair<int, int>> Node; // weight, destination

  distance[source] = 0;
  Node.insert({0, source});

  while (Node.size() > 0) {
    auto node = *Node.begin();
    int currentNode = node.second;
    int dist = node.first;

    Node.erase(Node.begin());

    if (visited[currentNode])
      continue;

    visited[currentNode] = true;

    for (auto child : graph[currentNode]) {
      int adjacent = child.first;
      int weight = child.second;
                        
      if (distance[currentNode] + weight < distance[adjacent]) {
        distance[adjacent] = distance[currentNode] + weight;
        Node.insert({distance[adjacent], adjacent});
      }
    }
  }

  std::cout << "\nShortest Distance of each node from source vertex 0 is: \n";
  for (int i = 0; i < graph.size(); i++) {
    std::cout << i << "\t" << distance[i] << "\n";
  }
}

int main(int argc, char *argv[]) {

  std::vector<std::pair<int, int>> node;

  node.push_back({1, 10});
  node.push_back({2, 3});
  graph.push_back(node);
  node.clear();
  
  node.push_back({3, 2});
  node.push_back({2, 1});
graph.push_back(node);
  node.clear();
  
  node.push_back({3, 2});
  // node.push_back({4, 8});
  node.push_back({4, 2});
graph.push_back(node);
  node.clear();

  node.push_back({4, 7});
graph.push_back(node);
  node.clear();
 
  node.push_back({3, 9});
  graph.push_back(node);
  node.clear();

  std::cout << "Graph is given below: \n";

  for ( int i = 0; i < graph.size(); i++) {
    for ( int j = 0; j < graph[i].size(); j++)  {
      std::cout << "current: " << i << "\t" << "adjacent: " << graph[i][j].first << "\t" << "weight: " << graph[i][j].second << "\n"; 
    }
  }


  dijkstra(0);
  return 0;
}
