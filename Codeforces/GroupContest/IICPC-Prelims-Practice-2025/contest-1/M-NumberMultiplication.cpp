#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
typedef unsigned long long ull;


ll mod_mul(ll a, ll b, ll M){
    //  (a * b) % c congruent to a*b - floor(ab / c) * c
    long long res = a * b - M * ll(1.L / M * a * b);
	return res + M * (res < 0) - M * (res >= (long long)M); // for precision handling
}

// Fast Exponentiation
ll mod_pow(ll a, ll d, ll mod) {
    ll res = 1;
    
    while (d > 0) {
        if (d & 1) { 
            res = (ll)res * a % mod;
        }
        a = (ll)a * a % mod;
        d >>= 1;
    }
    return res;
}

// Miller-Rabin primality test
bool is_prime(ll n) {
    // quick prime check, n < 2 -> rules out 1.
    // any prime number p, where p > 3, we can express them as 6K + 1 or 6k - 1.
    // Now such prime, p % 6 == 1 or p % 6 == 5, and % 4 == 1, 
    // So the condition n % 6 % 4 != 1 filters out numbers that are definitely not prime.
    if (n < 2 || (n % 6 % 4 != 1)) {
        return (n | 1) == 3; // this is for 2 and 3, edge cases
    }

    

    // From Fermat's little theorem we have, 
    // a^(n - 1) == 1 (mod n), where a is between 1 to n - 1

    ll d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    vector<ll> temp = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : temp) {
        ll p = mod_pow(a, d, n), i = s;
		while(p != 1 && p != n - 1 && a % n && i--) {
            p = mod_mul(p, p, n);
        }
		if(p != n - 1 && i != s) {
            return false;
        }
    }
    return true;
}


// Pollard's Rho function
ll pollard(ll n) {
	auto f = [n](ll x){ return mod_mul(x, x, n) + 1; };
	ll x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while(t ++ % 40 || __gcd(prd, n) == 1){
		if(x == y) x = ++ i, y = f(x);
		if(q = mod_mul(prd, max(x, y) - min(x, y), n)) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}

// Factorization
map<ll, vector<ll>> dp;
vector<ll> factorize(ll n) {
    if (n == 1) {
        return {};
    }
    
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    cout << n << "\n";
    if (is_prime(n)) {
        return {n};
    }

    ll d = pollard(n);
    vector<ll> left = factorize(d);
    vector<ll> right = factorize(n / d);
    left.insert(left.end(), right.begin(), right.end());
    return dp[n] = left;
}

int m, n, k;
vector<ll> a;
vector<set<pair<int, int>>> edge;

void solve() {
    cin >> m >> n >> k;
    edge.resize(n + 1);

    a.push_back(-1);
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        a.push_back(c);
    }
    
    for (int i = 0, _m, _n, d; i < k; i++) {
        cin >> _m >> _n >> d;
        edge[_n].insert({_m, d});
    }
    vector<ll> ans(m + 1);

    for (int i = 1; i <= n; i++) {
        ll c = a[i];
        vector<ll> factors = factorize(c);
        vector<pair<ll, int>> vp;
        sort(range(factors));

        for (int i = 0; i < factors.size(); ) {
            int r = i;
            while (r < factors.size() && factors[r] == factors[i]) {
                r++;
            }
            vp.push_back({factors[i], r - i});
            i = r;
        } 
        
        int k = 0;
        for (auto &p: edge[i]) {
            ans[p.first] = vp[k].first;
            k++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    solve();

    return 0;
}