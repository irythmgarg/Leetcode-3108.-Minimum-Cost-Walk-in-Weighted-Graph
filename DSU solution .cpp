class Solution {
public:
    // Arrays to store parent of each node and the minimum cost in the connected component
    vector<int> parent;
    vector<int> cost;

    // Find operation with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union operation that merges two sets and updates the cost at the root
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;  // Already connected
        parent[py] = px;       // Merge py into px
        cost[px] &= cost[py];  // Update the minimum cost using bitwise AND
    }

    // Main function to process edges and queries
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        cost.resize(n);

        // Initialize each node as its own parent and cost to all bits 1 (-1)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            cost[i] = -1;
        }

        // Process each edge: unite the nodes and update the root cost with AND of edge cost
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int cos = edge[2];

            if (find(from) != find(to)) {
                unite(from, to);
            }

            int root = find(from);
            cost[root] &= cos; // Update cost of the root
        }

        vector<int> ans;
        // Process queries to determine minimum cost between pairs if connected
        for (auto& quer : query) {
            int first = quer[0];
            int second = quer[1];
            if (find(first) == find(second))
                ans.push_back(cost[find(first)]); // Same component, return cost
            else
                ans.push_back(-1); // Not connected
        }

        return ans;
    }
};
