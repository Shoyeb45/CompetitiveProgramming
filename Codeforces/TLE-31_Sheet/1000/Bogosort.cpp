#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<int> a;
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    sort(a.rbegin(), a.rend());

    for(auto x: a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}