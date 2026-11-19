class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        int allVisited = (1 << n) - 1;
        
        // seen[node][mask] prevents duplicate states
        bool seen[12][1 << 12];
        memset(seen, false, sizeof(seen));

        // Queue stores {current_node, visited_mask}
        queue<pair<int, int>> q;

        // Start BFS simultaneously from every node
        for (int i = 0; i < n; ++i) {
            int initialMask = 1 << i;
            q.push({i, initialMask});
            seen[i][initialMask] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [u, mask] = q.front();
                q.pop();

                for (int v : graph[u]) {
                    int nextMask = mask | (1 << v);
                    
                    // Reached all nodes
                    if (nextMask == allVisited) {
                        return steps + 1;
                    }

                    if (!seen[v][nextMask]) {
                        seen[v][nextMask] = true;
                        q.push({v, nextMask});
                    }
                }
            }
            steps++;
        }

        return 0;
    }
};