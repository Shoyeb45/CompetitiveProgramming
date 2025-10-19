#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

const int N = 2e5 + 1;
static vector<int> spf[N];

void build_spf() {
    vector<int> is_prime(N, true);
    is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            spf[i].push_back(i);
            for (ll j = 2 * i; j < N; j += i) {
                spf[j].push_back(i);
                is_prime[j] = false;
            }
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> st;
    map<int, int> factors;
    int even = 0;

    for (int &x: a) {
        cin >> x;
        if (x != 1) {
            st.insert(x);
            for (int factor: spf[x]) {
                factors[factor]++;
            }
        }

        even += (x % 2 == 0);
    }
    for (int &x: b) {
        cin >> x;
    }
    for (auto it: factors) {
        if (it.second > 1) {
            cout << 0 << "\n";
            return;
        }
    }

    if (even == 1) {
        cout << 1 << "\n";
        return;
    }

    for (auto it: st) {
        int nx = it + 1;
        for (int factor: spf[nx]) {
            if (factors.find(factor) != factors.end()) {
                cout << 1 << "\n";
                return;
            }
        }
    }
    cout << 2 << "\n";
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
    build_spf();
    
    while (tt--) {
        solve();
    }

    return 0;
}