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

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i < 2 * n; i++) {
        cout << 1 << " ";
    }   
    cout << b << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("input_c.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i =1; i <= tt; i++) {
        solve(i);
    }

    return 0;
}