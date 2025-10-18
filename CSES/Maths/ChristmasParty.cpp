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

/*

Christmas Party(https://cses.fi/problemset/task/1717/)

# Prerequisite:
-> Basic Combinatorics, Derangement, Principal of Inclusion-Exclusion

# Main Idea:
-> Here the task is to find the number of ways of distributing the gifts such that the owner of that gift should not get the gift.
   We can change the problem statement slightly, that is we have n elements and we need to arrange each element in such that the ith 
   element should not come to the ith position. We need to find number of such arrangements.
-> This is classic problem of derangements. That is we need to find dearrangment of n.
1) We can use PIE to find such arrangements, 
number of derangements with n elements = number of all permutation - number of all permutation where ith element is at ith index
                                         = n! - N
Using PIE, N comes out to be:, N = summation from (k = 1 to k = n) { (-1)^(k + 1) * n! / k! }
See this link for detail: https://brilliant.org/wiki/derangements/

2) Recurrence relation
-> The recurrance relation is :
D[n] = (n - 1)(D[n - 1] + D[n - 2])
See coding part.

Solution:

1. Initialise the array with n + 1 elements
2. Specify base cases, i.e., D[0] = 1, D[1] = 0
3. Use recurrance relation to fill the values.

Complexties:
1. Time Complexity: O(n)
2. Space Commplexity: O(n)

Optimization:
We can optimize space complextiy from O(n) -> O(1). Since we only need D[i - 1] and D[i - 2], so we can keep the variables for that.
*/


void solve() {
    int n;
    cin >> n;
    vector<ll> D(n + 1, 0);

    D[0] = 1;

    for (int i = 2; i <= n; i++) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;
    }
    cout << D[n] << "\n";
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