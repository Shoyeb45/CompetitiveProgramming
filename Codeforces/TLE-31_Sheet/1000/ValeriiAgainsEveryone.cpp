#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<int> a;

bool isUnique(vector<int> &a) {
    sort(range(a));
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] == a[i + 1]) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    if(isUnique(a)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
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