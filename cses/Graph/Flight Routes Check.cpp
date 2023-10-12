#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, radj;  
vector<bool> visited;

void dfs(int node, const vector<vector<int>>& graph) {
    visited[node] = true;
    for(int u : graph[node]) {
        if(!visited[u])
            dfs(u, graph);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, vector<int>());
    radj.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }


    dfs(1, adj);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(1, radj);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
