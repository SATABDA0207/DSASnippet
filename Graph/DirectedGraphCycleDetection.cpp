#include<bits/stdc++.h>
using namespace std;

class DirectedGraphCycleDetection
{
public:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited, recStack;
    
    DirectedGraphCycleDetection(int n){
        this->n = n;
        adj.resize(n);
        visited.assign(n, false);
        recStack.assign(n, false);
    }

    void addEdge(int i, int j){
        adj[i].push_back(j);
    }

    bool dfs(int i){
        visited[i] = true;
        recStack[i] = true;
        for(int j : adj[i]){
            if(!visited[j]){
                if(dfs(j)) return true;
            } else if(recStack[j]){
                return true;
            }
        }
        recStack[i] = false;
        return false;
    }

    bool hasCycle(){
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i)) return true;
            }
        }
        return false;
    }
};

int main() {
    DirectedGraphCycleDetection g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // creates cycle

    if (g.hasCycle())
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}

