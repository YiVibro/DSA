#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 1. DSU Structure (Reusing what you learned)
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) parent[rootU] = rootV;
    }
};

// 2. Edge Structure
struct Edge {
    int u, v, weight;
    // Comparator for sorting
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& adj) {
        vector<Edge> edges;
        
        // Convert Adjacency list to Edge list
        // Note: Input format varies, assuming adj[u] = {v, w}
        // If input is already an edge list, just sort that directly.
        for (int u = 0; u < V; u++) {
            for (auto& it : adj[u]) {
                int v = it[0];
                int w = it[1];
                if (u < v) { // Avoid adding same edge twice for undirected graph
                    edges.push_back({u, v, w});
                }
            }
        }

        // Step 1: Sort edges by weight
        sort(edges.begin(), edges.end());

        DSU dsu(V);
        int mstWeight = 0;
        int edgesCount = 0;

        // Step 2: Iterate and build MST
        for (auto& edge : edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unionSets(edge.u, edge.v);
                mstWeight += edge.weight;
                edgesCount++;
            }
        }

        return mstWeight;
    }
};