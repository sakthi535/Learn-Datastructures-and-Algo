#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

// Count number of nodes in given level n

using namespace std;

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<vector<int>> V(n, vector<int>(n, 0));
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;

        V[a][b]++;
        V[b][a]++;
    }
    
    map<int, int> isVisited;
    for(int i=0;i<n;i++){isVisited[i] = 0;}
    
    queue<int> Q;
    Q.push(0);
    isVisited[0] = 1;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        cout << "Node : " << v << " " << "level : " << isVisited[v] << "\n"; 


        for(int i=0;i<n;i++){
            if(V[v][i] and isVisited[i] == 0){
                Q.push(i);
                isVisited[i] = isVisited[v]+1;
            }
        } 
    }


    return 0;
}