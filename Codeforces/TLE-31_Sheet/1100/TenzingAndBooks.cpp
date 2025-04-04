#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, x;
vector<int> a[3];

void solve() {
    cin >> n >> x;

    for(int i = 0; i < 3; i++) {
        a[i].resize(n);
        for(auto &x: a[i]) {
            cin >> x;
        }
    }

    if(x == 0) {
        cout << "YES\n";
        return;
    }

    int knw = 0;


    for(int i = 0; i < 3; i++) {
        for(auto y: a[i]) {
            if((y | x) != x) {
                break;
            }
            knw |= y;
        }
    }

    if(knw != x) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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