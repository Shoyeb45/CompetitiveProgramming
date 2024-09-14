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
    // Two pointers solution

    cin >> n >> m;
    vector<int> a(n), b(m);

    loop(i, n)
        cin >> a[i];
    loop(j, m) 
        cin >> b[j];

    int ans = 0;
    int j = 0, i = 0;
    for(int i = 0; i < n; i++) {
        int curr = a[i];
        int cntA = 1, idx = i + 1;
        while(idx < n && curr == a[idx]) {
            idx++, cntA++;
        }

        while(j < m && b[j] < curr) {
            j++;
        }

        int cntB = 0;
        while(j < m && b[j] == curr) {
            j++, cntB++;
        }

        ans += (cntA * cntB);
        i = idx - 1;
    }
   
    cout << ans << '\n';
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
