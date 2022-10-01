#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int findScore(int a, vector<vector<int>> A, int n){
    int score=0;
    for(int i=0;i<n;i++){
        if(A[a][i]){
            score += findScore(i, A, n);
        }
    }
}

int main()
{
    fastio;

    int n,e;
    cin >> n >> e;

    vector<vector<int>> A(n+1, vector<int>(n+1, 0));
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;

        A[a][b]++;
    }

    vector<int> Score(n+1, 0);

    for(int i=0;i<=n;i++){
        Score[i] = findScore(i, A, n);
    }


    return 0;
}