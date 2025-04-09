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

int n, m;
void solveBS() {
    // Binary Search Solution 
    // TC : O(n * log(m))
    cin >> n >> m;
    vector<int> a(n), b(m);
    loop(i, n)
        cin >> a[i];
    loop(j, m) 
        cin >> b[j];
    
    ll ans = 0;
    loop(i, n) {
        ans += (upper_bound(range(b), a[i]) - lower_bound(range(b), a[i]));
    }
    cout << ans << '\n';
}

void solveTP() {
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    ll ans = 0;

    for (int i = 0, j = 0; i < n && j < m; ) {
        if (a[i] == b[j]) {     
            int temp_i = i, temp_j = j;
            while (temp_i < n && a[temp_i] == a[i]) {
                temp_i++;
            }

            while (temp_j < m && b[temp_j] == b[j]) {
                temp_j++;
            }

            // cout << (temp_j - j) << " " << (temp_i - i) << "\n"; 
            ans += 1LL * (temp_j - j) * (temp_i - i);
            i = temp_i, j = temp_j;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            i++;
        }
    }

    cout << ans << "\n";
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solveTP();
    }
    
    return 0;
}
