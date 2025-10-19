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

ll factorial[21];


/**

k=42
1 2 3 4 5

1 -> [1 23]
2 -> [24 47]  <- 41

First number 2

rem: 1 3 4 5
2 _ _ _ _

1 -> [24 29]
3 -> [30 35]
4 -> [36 42] <- 41, choose 3

so ans : 2 4 _ _ _
rem: 1 3 5
1 -> [36 37]
3 -> [38 39]
5 -> [40 41]  <- 41, choose 5

so ans : 2 4 5 _ _ 
rem: 1 3
1 -> [40 40]
3 -> [41 41] <- 41, choose 5

 */
void solve_case_1() {
    int n;
    ll k;
    cin >> n >> k;
    k--;
    vector<int> ans(n);
    set<int> rem;

    for (int i = 1; i <= n; i++) {
        rem.insert(i);
    }
    ll low = 0;
    for (int i = 0; i < n; i++) {
        int sz = rem.size();
        ll fact = factorial[sz - 1] - 1;
        auto it = rem.begin();

        while (true) {
            ll high = low + fact;
            if (k >= low && k <= high) {
                ans[i] = *it;
                rem.erase(*it);
                break;
            } else {
                low = high + 1;
            }
            it = next(it);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

void solve_case_2() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i: p) {
        cin >> i;
    }
    ll ans = 1;
    set<int> rem;
    for (int i = 1; i <= n; i++) {
        rem.insert(i);
    }
    for (int i = 0; i < n - 1; i++) {
        ll low = ans;
        auto it = rem.begin();
        ll fact = factorial[rem.size() - 1];
        while (*it != p[i]) {
            low = low + fact;
            it = next(it);
        }
        ans = low;
        rem.erase(*it);
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
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= 20; i++) {
        factorial[i] = 1LL * i * factorial[i - 1];
    }

    while (tt--) {
        int case_num;
        cin >> case_num;
        if (case_num == 1) {
            solve_case_1();
        } else {
            solve_case_2();
        }
    }

    return 0;
}