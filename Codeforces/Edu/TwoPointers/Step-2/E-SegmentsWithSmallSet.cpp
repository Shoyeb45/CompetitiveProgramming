#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
int counter[(int)(1e5 + 1)];

int n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    int left = 0, uniqueEle = 0;
    ll ans = 0;
    for(int right = 0; right < n; right++) {
        counter[a[right]]++;
        if(counter[a[right]] == 1) {
            uniqueEle++;
        }

        while(left < n && uniqueEle > k) {
            counter[a[left]]--;
            if(counter[a[left]] == 0) {
                uniqueEle--;
            }
            left++;
        }
        ans += (right - left + 1);
    }

    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}