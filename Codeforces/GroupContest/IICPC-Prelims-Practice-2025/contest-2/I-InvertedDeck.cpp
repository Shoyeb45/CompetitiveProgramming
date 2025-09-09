#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a;
void solve() {
    
    cin >> n;
    a.resize(n);
    for (int &x: a) {
        cin >> x;
    }
    if (is_sorted(range(a))) {
        cout << 1 << " " << 1 << "\n";
        return;
    }

    vector<bool> is_sorted_p(n, false), is_sorted_s(n, false);
    is_sorted_p[0] = true;

    for (int i = 1; i < n; i++) {
        is_sorted_p[i] = (a[i] >= a[i - 1]) && is_sorted_p[i - 1];
    }

    is_sorted_s[n - 1] = true;
    for (int i = n - 2; i >= 0; i--) {
        is_sorted_s[i] = (a[i] <= a[i + 1]) && is_sorted_s[i + 1];
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            int j = i;
            while (j < n - 1 && a[j] >= a[j + 1]) {
                j++;
            }

            bool is_both_sides_sorted = (i - 1 >= 0 ? is_sorted_p[i - 1]: true) && (j + 1 < n? is_sorted_s[j + 1]: true);

            bool ok = (i - 1 >= 0? a[i - 1] <= a[j]: true) && (j + 1 < n? a[i] <= a[j + 1]: true);

            if (is_both_sides_sorted && ok) {
                cout << i + 1 << " " << j + 1 << "\n";
                return; 
            }
            i = j;
        }
    }
    cout << "impossible\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}