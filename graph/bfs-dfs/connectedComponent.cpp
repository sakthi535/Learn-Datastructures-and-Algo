#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

// CSES : make bridges

using namespace std;

#define ll long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


class Graph{
    public:
        ll v,e;
        vector<int> Adj[100000];
        vector<ll> visited;
        vector<ll> temp;

        void dfs(long long i, long long comp){
            visited[i] = comp;
            for(auto j:Adj[i]){
                if(visited[j] == 0){
                    dfs(j,comp);
                }
            }
        }
};




int main()
{
    fastio;
    

    Graph city;

    cin >> city.v;
    cin >> city.e;

    // city.Adj = vector<vector<long long>>(city.v+1, vector<long long>(city.v+1, 0));
    city.visited = vector<long long>(city.v+1, 0);

    for(long long i=0;i<city.e;i++){
        long long a,b;
        cin >> a >> b;

        city.Adj[a].push_back(b);
        city.Adj[b].push_back(a);
    }

    for(long long i=0;i<=city.v;i++){
        city.visited[i] = 0;
    }
    vector<long long> temp;
    for(long long i=1;i<=city.v;i++){
        if(city.visited[i] == 0){
            temp.clear();
            city.dfs(i, i);
        }
    }
    
    map<long long, long long> hash;
    for(long long i=1;i<=city.v;i++){
        hash[i] = 0;
    }   

    long long ans=0;
    vector<long long> res;

    // // cout << "*\n";


    for(long long i=1;i<=city.v;i++){
        if(!hash[city.visited[i]]){
            res.push_back(city.visited[i]);
            ans++;
            hash[city.visited[i]] = 1;
        }
    }

    cout << ans-1 << '\n';
    for(long long i=0;i<ans-1;i++){
        cout << res[i] << ' ' << res[i+1] << '\n';
    }

    return 0;
}