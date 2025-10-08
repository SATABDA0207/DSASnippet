#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> vis(n, -1);
    queue<int> q;
    q.push(start);
    vis[start] = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nei : adj[node]) {
            if (vis[nei] == -1) {
                vis[nei] = vis[node] + 1;
                q.push(nei);
            }
        }
    }
}