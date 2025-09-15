#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    } 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s1 = 0, s2 = 0, s3 = 0;
            for (int k = 0; k <= i; k++) {
                s1 += a[k];
            }
            for (int k = i + 1; k <= j; k++) {
                s2 += a[k];
            }
            for (int k = j + 1; k < n; k++) {
                s3 += a[k];
            }

            set<int> temp;
            temp.insert(s1 % 3);
            temp.insert(s2 % 3);
            temp.insert(s3 % 3);

            if (temp.size() == 3 || temp.size() == 1) {
                cout << i + 1 << ' ' << j + 1 << "\n";
                return;
            }
        }
    }
    cout << 0 << " " << 0 << "\n";
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