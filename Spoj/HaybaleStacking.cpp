// How to use prefix sum in reverse way, i.e, to use the ranges to build the prefix sum array. (Indeed beautiful)

#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k;
void solve() {
    cin >> n >> k;

    vector<int> diff(n + 2, 0);
    while(k--) {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b + 1]--;
    }   

    vector<int> sum(n + 1, 0);
    int pref = 0;
    for(int i = 1; i <= n; i++) {
        pref += diff[i];
        sum[i] = pref;
    }   

    sort(range(sum));

    cout << sum[(n + 1) / 2] << '\n'; 
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
