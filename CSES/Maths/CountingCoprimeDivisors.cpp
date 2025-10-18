#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
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
const int MAX_N = 1e6 + 1;

ll mu[MAX_N]; // Mobius Inversion
ll cnt[MAX_N]; // cnt[i] : number of elements in the array which is divisible by i

void mobius() {
    vector<int> prime;
    bool is_composite[MAX_N];
    fill(is_composite, is_composite + MAX_N, false);
    mu[1] = 1;

    for (int i = 2; i < MAX_N; i++) {
        if (!is_composite[i]) {
            prime.push_back(i);
        }
    }
}
void solve() {
    
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