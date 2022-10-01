#include <bits/stdc++.h>
using namespace std;

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void IS_BRIDGE(int a,int b){
    cout << a << ' ' << b << "**++**\n";
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            // low[v] = min(low[v], low[to]);
            cout << low[v] << ' ' << tin[v] << "*\n";
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
            // cout << i << "\n";
    }
}

int main(){
    int v,e;
    cin >> n >> e;

    timer = 0;
    adj = vector<vector<int>>(n);
    // visited = vector<bool>(n+1, false);
    // tin = low = vector<int>(n+1, 0);

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_bridges();

    for(auto i:visited){
        cout << i << ' ';
    }
    cout << "\n";

    for(auto i:low){
        cout << i << ' ';
    }
    cout << "\n";

    for(auto i:tin){
        cout << i << ' ';
    }
    cout << "\n";
    
    
}