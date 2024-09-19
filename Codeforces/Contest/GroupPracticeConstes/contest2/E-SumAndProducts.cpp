#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
vector<ll> a;

bool isInteger(double d) {
	return abs(d - round(d)) < 1e-9;
}

bool isPerfectSquare(ll x) {
	ll root = sqrt(x);
    return root * root == x;
}

void solve() {
	cin >> n;
	a.resize(n);
	map<ll, ll> mp;

	for(auto &x: a) {
		cin >> x;
		mp[x]++;
	}

	cin >> q;

	while(q--)  {
		ll x, y;
		cin >> x >> y;

		ll discriminant = 1LL * x * x - 4 * y;

		if(discriminant < 0 || !isPerfectSquare(discriminant)) {
			cout << 0 << " ";
			continue;
		}


		ll rootD = sqrt(discriminant);
        ll a1 = (x + rootD) / 2;
        ll a2 = (x - rootD) / 2;

        if ((x + rootD) % 2 == 0 && (x - rootD) % 2 == 0) {
            ll n1 = mp[a1], n2 = mp[a2];

            if(a1 == a2) {
                ll ans = 1LL * n1 * (n1 - 1);
                cout << (ll)(ans / 2) << " ";
            }
            else {
                ll ans = n1;
                cout << 1LL * ans * n2 << " ";
            }
        }
        else {
            cout << 0 << " ";
        }
	}

	cout << "\n";
}

int main() {
	NFS
	int tt;
	tt = 1;
	cin >> tt;

	while (tt--) {
		solve();
	}
	
	return 0;
}
