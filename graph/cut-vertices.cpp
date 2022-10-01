#include <bits/stdc++.h>

// Cut Vertices or articulation points
// Vertices if removed, increases number of components

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

int n;
vector<vector<int>> adj;
vector<bool> visited;

vector<int> tin,low;
int timer;

using namespace std;

void dfs(int v, int p=-1){
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(int to: adj[v]){
        if(to == p){continue;}
        if(visited[to]){
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] && p!=-1){
                cout << v << "\n";
            }
            ++children;
        }
    }

    if(p == -1 && children >=2){
        cout << v << "\n";
    }
}

void find_cutpoint(){
    timer =0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main()
{
    fastio;
    

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

    find_cutpoint();


    return 0;
}