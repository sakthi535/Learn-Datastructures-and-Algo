#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<vector<int>> A(n+1, vector<int>(n+1, 0));
    int e;
    cin >> e;

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;

        A[a][b]++;
        A[b][a]++;
    }

    queue<int> Q;
    int r;
    cin >> r;

    map<int, int> isVisited;
    for(int i=0;i<e;i++){isVisited[i] = 0;}

    Q.push(r);
    while(!Q.empty()){
        int v =Q.front();
        isVisited[r] = 1;
        Q.pop();

        cout << "Visited Node : " << v << "\n"; 
        for(int i=0;i<n;i++){
            if(A[v][i] and isVisited[i]==0){
                isVisited[i] = 1;
                Q.push(i);
            }
        }

    }

    
    return 0;
}