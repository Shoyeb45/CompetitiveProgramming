#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
int l, r;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    
    vector<int> p(n + 1);
    p[1] = -1;
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            p[i] = i - 1;
        }
        else {
            p[i] = p[i - 1];
        }
    }

   
    cin >> q;
    while(q--) {
        cin >> l >> r;

        if(p[r] >= l) {
            cout << p[r] << " " << r << "\n";
        }
        else {
            cout << -1 << " -1\n";
        }
    }
    cout << "\n";
}

int main() {
    NFS
    auto begin = std::chrono::high_resolution_clock::now();
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    for(int i = 1;  i <= 1e9; i++) {
        cout << ".";
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    
    return 0;
}