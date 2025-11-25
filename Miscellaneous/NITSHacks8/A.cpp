#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
typedef long long ll;
const ll mod = 998244353;

ll mod_pow(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if ((b & 1)) {
      ans = (1LL * ans * a) % mod;
    }
    a = (1LL * a * a) % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  reverse(range(a));

  if (x == 1) {
    ll ans = 0;

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && a[i] == 1) {
        ans++;
      } else if (i % 2 == 1 && a[i] == 0) {
        ans++;
      }
    }
    ll ans2 = 0;

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && a[i] == 0) {
        ans2++;
      } else if (i % 2 == 1 && a[i] == 1) {
        ans2++;
      }
    }
    cout << min(ans, ans2) << "\n";
    return;
  }

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      int idx = n - i;
      ans = ((ll)ans + 1LL * mod_pow(x, idx)) % mod;
      a[i] = 1 - a[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  NFS
#ifndef ONLINE_JUDGE
      freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/"
              "in.txt",
              "r", stdin);
  freopen(
      "/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt",
      "w", stdout);
  freopen(
      "/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt",
      "w", stderr);
#endif
  int tt;
  tt = 1;
  cin >> tt;

  for (int i = 1; i <= tt; i++) {
    solve();
  }

  return 0;
}