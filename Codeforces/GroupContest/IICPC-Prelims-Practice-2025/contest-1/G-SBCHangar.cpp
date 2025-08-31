#include<bits/stdc++.h>
//vivaanpc
using namespace std;
//vivaanpc
typedef long long ll;
;
ll countWays(const vector<ll>& weights, int idx, int rem, ll curr, ll a, ll b) {
	if (rem == 0) {
		return (curr >= a && curr <= b) ? 1 : 0;
	}
	if (idx >= weights.size() || rem > weights.size() - idx) {
		return 0;
	}
	ll count = 0;
	count += countWays(weights, idx + 1, rem, curr, a, b);
	if (curr + weights[idx] <= b) {
		count += countWays(weights, idx + 1, rem - 1, curr + weights[idx], a, b);
	}
	return count;
}
//vivaanpc
void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	ll a, b;
	cin >> a >> b;
	ll result = countWays(weights, 0, k, 0, a, b);
	cout << result << "\n";
}
//vivaanpc
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;

	while (t--) {
		solve();
	}
	return 0;
}
