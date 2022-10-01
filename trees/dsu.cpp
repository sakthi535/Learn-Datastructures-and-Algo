#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class DSU{
    private:
        int n;
        vector<int> parent, size;
    public: 
        DSU(int n){
            parent.assign(n, 0);
            size.assign(n,0);

            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find_set(int a){
            if(parent[a] == a){
                return a;
            }
            return parent[a] = find_set(a);
        }

        void union_set(int a, int b){
            a = find_set(a);
            b = find_set(b);

            if(a!=b){
                if(size[a] < size[b]){
                    swap(a,b);
                }
                parent[b] = a;
                size[a] += size[b];
            }   
        }

        void display(){
            for(auto i:parent){
                cout << i << ' ';
            }
            cout << '\n';

            for(auto i:size){
                cout << i << ' ';
            }
            cout << '\n';
        }

};



int main()
{
    fastio;
    
    int n;
    cin >> n;
    DSU obj(n);

    int q=4;
    // cin >> q;

    obj.display();
    for(int i=0;i<q;i++){
        // int a,b;
        // cin >> a >> b;

        obj.union_set(2,3);
    }
    obj.display();


    return 0;
}