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
    int k = 4;
    string s;

    while (k > 2) {
        cout << "next 0 1" << endl;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> s;
        }
        cout << "next 0" << endl;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> s;
        }
    }

    k = 2;
    while (k > 1) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> s;
        }
    }

    cout << "done" << endl;
}

int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}