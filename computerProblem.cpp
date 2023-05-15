#include<bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> graph;    // first element represents weight and other represent source and vertex


int parent[1001];

// Find the parent of the node
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

// Merge the two sets
void merge(int a, int b) {
    parent[find(a)] = find(b);
}


// Kruskal's algorithm
void kruskal(set<graph>& edges, int n) {
    int cost = 0;
    vector<graph> discarded;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    while (edges.size() > 0) {
        cout << "\n";
        auto edge = *edges.begin();
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << w << " " << u << " " << v << "\n";
        if (find(u) == find(v)) {
            discarded.push_back({w,{u,v}});
        }
        edges.erase(edges.begin());
    }
    cout << "Number of discarded edges are: " << discarded.size() << endl;
    for (int i = 0 ; i < discarded.size(); i++) {
        cout << discarded[i].second.first << " - " << discarded[i].second.second << endl;
    }
}


int main()  {

    // system("clear");
    set<graph> edges;
    int n, e;
    cout << "nodes edges\n";
    cin >> n >> e;
    cout << endl << "weight source destination\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> w >> u >> v;
        edges.insert({w, {u, v}});
    }
    kruskal(edges, n);

    return 0;
}