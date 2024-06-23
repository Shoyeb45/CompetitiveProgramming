#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void generate_subset(vector<vector<int>> &a, int n) {
    a.resize((1 << n));
    for(int i = 1; i < (1 << n); i++) {
        for(int j = 0; j < ((int)log2(i) + 1); j++) {
            if(((i >> j) & 1)) {
                a[i].push_back(j + 1);
            }
        }
    }
}

// Generate power set of set - {x: x is [1, n]}
int n; // (n = 1 ... 19)
void solve() {
    cin >> n;
    vector<vector<int>> power_set;
    cout << "Total Number of subset: " << (1 << n) << '\n';
    generate_subset(power_set, n);
    loop(i, power_set.size()) {
        if(power_set[i].size() == 0) {
            cout << "{}" << '\n';
            continue;
        }
        cout << "{";
        loop(j, power_set[i].size()) {
            if(j == power_set[i].size() - 1) {
                cout << power_set[i][j] << "}";
            } else
                cout << power_set[i][j] << ", ";
        }
        cout << '\n';
    }
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
