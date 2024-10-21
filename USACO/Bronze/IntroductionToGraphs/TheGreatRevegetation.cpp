#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    set<int> adj[n + 1];

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }


    cout << 1;
    vector<int> fields[5];
    fields[1].push_back(1);

    for(int i = 2; i <= n; i++) {
        // cout << "fields: " << "\n";
        // for(int i = 1; i <= 4; i++) {
        //     cout << i << " :";
        //     for(auto x: fields[i]) {
        //         cout << x << " ";
        //     } 
        //     cout << "\n";
        // }
        for(int j = 1; j < 5; j++) {
            if(fields[j].empty()) {
                cout <<  j;
                fields[j].push_back(i);
                break;
            }
            else {
                bool ans = 1;
                for(int pasture: fields[j]) {
                    if(adj[pasture].find(i) != adj[pasture].end()) {
                        ans = 0;
                        break;
                    }
                }
                if(ans) {
                    fields[j].push_back(i);
                    cout << j;
                    break;
                }   
            }
        }
    }

    
}

int main() {
    NFS
    int tt;
    tt = 1;
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    // #endif
        freopen("revegetate.in", "r", stdin);
        freopen("revegetate.out", "w", stdout);

    while (tt--) {
        solve();
    }
    
    return 0;
}
