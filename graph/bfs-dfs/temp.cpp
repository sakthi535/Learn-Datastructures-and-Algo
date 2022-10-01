#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;

    vector<int> A[5];
    for (int i = 0; i < 5; i++) {
  
        for (int j = i + 1; j < 5; j++) {
            A[i].push_back(j);
        }
    }
    for(auto i:A){
        for(auto j:i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    return 0;
}