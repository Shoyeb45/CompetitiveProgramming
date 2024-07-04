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

vector<int> mergeArray(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0, k = 0;
    vector<int> ans(n + m);

    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            ans[k++] = a[i++];
        } else {
            ans[k++] = b[j++];
        }

    }

    while(i == n && j < m) {
        ans[k++] = b[j++];
    }
    while(j == m && i < n) {
        ans[k++] = a[i++];
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    loop(i, n)
        cin >> a[i];
    loop(i, m)
        cin >> b[i];    
    
    vector<int> c = mergeArray(a, b);
    loop(i, n + m) {
        cout << c[i] << ' ';
    }
    cout << '\n';
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
