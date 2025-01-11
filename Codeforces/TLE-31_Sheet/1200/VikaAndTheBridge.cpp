#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int n, k;
vector<int> a;

bool check(int mid) {
    vector<int> cnt(k + 1, 0), lastIdx(k + 1, -1);

    for (int i = 0; i < n; i++) {
        int dist = i - lastIdx[a[i]] - 1;
        if (dist > mid) {
            if (dist % 2 == 0) {
                if ((dist / 2) + 1 <= mid) {
                    cnt[a[i]]++;
                }
                else {
                    cnt[a[i]] = 1e7;
                }
            }
            else {
                if ((dist / 2) <= mid) {
                    cnt[a[i]]++;
                }
                else {
                    cnt[a[i]] = 1e7;
                }
            }
        }
        lastIdx[a[i]] = i;
    }


    for (int i = 1; i <= k; i++) {
        int x = cnt[i];
        if (x <= 1) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
        // debug("mid", mid);
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}