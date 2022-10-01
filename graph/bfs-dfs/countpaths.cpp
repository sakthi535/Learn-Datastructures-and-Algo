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

    int e;
    cin >> e;

    int a,b;
    vector<vector<int>> A(n, vector<int>(n,0));
    for(int i=0;i<e;i++){
        cin >> a >> b;

        A[a][b]++;
    }

    cin >> a >> b;

    stack<int> Q;
    Q.push(a);
    int ans=0;

    map<int, int> isVisited;
    for(int i=0;i<n;i++){isVisited[i] = 0;}

    while(!Q.empty()){
        int v = Q.top();
        Q.pop();

        for(int i=0;i<n;i++){
            if(isVisited[i]==0 and A[v][i]){
                if(i == b){
                    ans++;
                }
                else{
                    Q.push(i);
                    isVisited[v] = 1;
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}