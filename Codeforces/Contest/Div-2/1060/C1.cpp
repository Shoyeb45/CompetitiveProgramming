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

const int MAX = 200001;
vector<int> spf(MAX);

void build_spf() {
    for (int i = 0; i < MAX; i++)
        spf[i] = i;

    for (int i = 2; i < MAX; i++) {
        if (spf[i] == i) { 
            for (int j = i; j < MAX; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


set<int> get_prime_factors(int x) {
    set<int> primes;
    if (x <= 1) return primes;
    while (x > 1) {
        int p = spf[x];
        primes.insert(p);
        while (x % p == 0)
            x /= p;
    }
    return primes;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int even_count = 0, odd = 0;
    for (auto &x: a) {
        cin >> x;
        even_count += (x % 2 == 0);
        odd += (x % 2 == 1);
    }   

    for (int &x: b) {
        cin >> x;
    }
    vector<set<int>> prime_factors(n);
    map<int, int> prime_count;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue;
        prime_factors[i] = get_prime_factors(a[i]);
        for (int p : prime_factors[i]) {
            prime_count[p]++;
        }
    }
    
    for (auto &it: prime_count) {
        int prime = it.first, cnt = it.second;
        if (cnt >= 2) {
            cout << 0 << '\n';
            return;
        }
    }

    
    bool can_cost_1 = false;
    for (int i = 0; i < n; i++) {
        int candidate = a[i] + 1;
        set<int> cand_primes = get_prime_factors(candidate);
        for (int p : cand_primes) {
            int available = prime_count[p];
            if (a[i] != 1 && prime_factors[i].count(p)) {
                available--;
            }
            if (available >= 1) {
                can_cost_1 = true;
                break;
            }
        }
        if (can_cost_1) break;
    }
    if (can_cost_1) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
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