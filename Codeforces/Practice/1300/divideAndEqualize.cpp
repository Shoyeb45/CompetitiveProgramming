#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;
#define MAX 1e6 + 1
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
int n;
vector<int> a;
vector<unordered_map<int, int>> divisors(MAX);
vector<bool> prime(MAX, true);

void sieve() {
    for(int i = 2; i < MAX; i++) {
        if(prime[i]) {
            for(int j = i; j < MAX; j += i) {
                int temp = j;
                while(temp % i == 0) {
                    divisors[j][i]++;
                    temp /= i;
                }
                prime[j] = 0;
            }
        }
    }
}

bool all_equal(vector<int> &a) {
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] != a[i + 1]) 
            return false;
    }
    return true;
}

void solve() {
    cin >> n;
    a.resize(n);
    loop(i, n) {
        cin >> a[i];
    }    
    
    // if(all_equal(a)) {
    //     cout << "YES\n";
    //     return;
    // }
    unordered_map<int, int> m;
    for(auto ele: a) {
        if(ele == 1) {
            m[ele] = n;
            continue;
        }
        for(auto div: divisors[ele]) {
            // cout << div.first << " * " << div.second << "  ";  
            m[div.first] += div.second;
            // cout << div.first << ' ';
            // cout << m[div.first] << '\n';
        }
        // cout << "\n";
    }

    for(auto it: m) {
        if(it.second % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    // for(auto it: m) {
    //     cout << it.first << ' ' << it.second << '\n';
    // }
    cout << "YES\n";
    // for(auto it: divisors[100]) {
    //     cout << it.first << ' ' << it.second << '\n';
    // }
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;
    sieve();
    while (tt--) {
        solve();
    }
    
    return 0;
}
