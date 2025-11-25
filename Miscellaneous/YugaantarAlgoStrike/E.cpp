#include <bits/stdc++.h>
// PriyanshuSingh18
using namespace std;
// PriyanshuSingh18
#define int int64_t
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define all(x) (x).begin(), (x).end()
#define fl(n) for (int i = 0; i < n; i++)
#define inp(vec, n)                                                            \
  for (int i = 0; i < n; i++) {                                                \
    cin >> vec[i];                                                             \
  }
// PriyanshuSingh18

const int mod = int(1e6) + 7;

int modd(int a, int b) { return (a + b) % mod; }

int submod(int a, int b) { return ((a - b) % mod + mod) % mod; }

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> pre(m + 1);
  vector<int> curr(m + 1);

  pre[0] = 1;

  for (int j = 1; j <= m; j++) {
    pre[j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    curr[0] = 1;

    for (int j = 1; j <= m; j++) {
      int ans = modd(curr[j - 1], pre[j]);

      int ind = j - a[i] - 1;
      if (ind >= 0) {
        ans = submod(ans, pre[ind]);
      }
      curr[j] = ans;
    }
  }

  cout << pre[m] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen(
      "/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt",
      "r", stdin);
  freopen(
      "/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt",
      "w", stdout);
  freopen(
      "/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt",
      "w", stderr);
#endif
  int t = 1;
//   cin >> t;
  while (t--)
    solve();
}