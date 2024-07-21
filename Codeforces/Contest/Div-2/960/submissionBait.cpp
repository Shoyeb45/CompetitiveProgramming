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

int n;

bool check(vector<int> &a) {
    sort(range(a));
    reverse(range(a));

    map<int, int> mp;
    loop(i, a.size()) {
        mp[a[i]]++;
    }

    for(auto it: mp) {
        if(it.second % 2 == 1)
            return !false;
    }
    return !true;
}
void solve() {
    cin >> n;
    vector<int> a(n);

    loop(i, n)
        cin >> a[i];

    cout << (check(a) ? "YES\n": "NO\n");
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
