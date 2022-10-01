#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> visited;

vector<int> tin, low;
int timer;

void dfs(int v, int p=-1){
    visited[v] = true;
    low[v] = tin[v] = timer++;
    int children = 0;
    for(auto to: graph[v]){
        if(to == p){continue;}
        else if(visited[to]){
            low[to] = min(low[v], tin[v]);
        }
        else{
            dfs(to, v);
            low[v] = min(low[to], low[v]);

            if(low[to] >= tin[v] && p!=-1){
                cout << v << "\n";
            }
            ++children;
        }
    }
    if(p == -1 && children > 1){
        cout << v << "-*-\n";
    }

}


int main()
{
    fastio;
    int e;
    cin >> n;
    cin >> e;
    graph = vector<vector<int>>(n);
    visited.assign(n, false);
    tin.assign(n,-1);
    low.assign(n, -1);
    timer =0;

    int a,b;
    for(int i=0;i<e;i++){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> a;
    dfs(a);
    return 0;
}