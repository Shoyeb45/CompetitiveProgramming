#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<int> primes;

void solve() {
    int n, k;
    cin >> n >> k;
    int index = primes.size() - 1;
    
    if (k > (n * (n - 1)) / 2) {
        cout << -1 << "\n";
        return;
    }
    
    while (n || k) {
        if (k >= n - 1) {
            cout << primes[index] << " ";
            k -= (n - 1);
            n--, index--;
        } else {
            if (index > 0) {
                cout << 6 << " ";
                index = 1;  
            } else {
                cout << 2 << " ";
            }
            n--;
        }
    }
    cout << "\n";
}

void generate_prime() {
    int mx = (int)2e6 + 1;
    vector<bool> is_prime(mx, true);

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < mx; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < mx; j += i) {
                is_prime[j] = false;
            }
        }
    } 
}
int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;
    generate_prime();
    while (tt--) {
        solve();
    }

    return 0;
}