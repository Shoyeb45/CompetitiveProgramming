#include<bits/stdc++.h>
//vivaanpc
using namespace std;
//vivaanpc
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<int> v(n), pref(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	pref[0] = v[0];
	for (int i = 1; i < n; ++i) {
		pref[i] = v[i] + pref[i - 1];
	}

	int m, k;
	cin >> m;
	while (m--) {
		cin >> k;
		if (k == 0) {
			cout << pref[n - 1] << "\n";
		} else {
			cout << pref[ceil(double(n) / (k + 1)) - 1] << "\n";
		}
	}
}
//vivaanpc
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}x  