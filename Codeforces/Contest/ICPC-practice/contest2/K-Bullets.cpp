#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<pair<int, int>> a;

void solve() {
    cin >> n;   
    a.resize(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }
    sort(range(a));
    int ans = 0;
    int i = 0;

    while(i < n) {
        int currInd = a[i].second;

        while(i + 1 < n && currInd - 1 >= 0 && a[i + 1].first == b[currInd - 1]) {
            i++, currInd--;
        }
        ans++;
        i++;
    }
    cout << ans << '\n';
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