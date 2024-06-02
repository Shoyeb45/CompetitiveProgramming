#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool is_subsequence(string o, string s) {
    int i = 0, j = 0;
    while(i < o.size() && j < s.size()) {
        if(o[i] == s[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    return (j == s.size());
}

bool check(string t, string s, vector<int> p, int mid) {
    for(int i = 0; i <= mid; i++) {
        t[p[i]] = '#';
    }
    string o = "";
    loop(i, t.size()) {
        if(t[i] != '#') {
            o += t[i];
        }
    }
    return is_subsequence(o, s);
}
void solve() {
    string t, s;
    cin >> t >> s;
    vector<int> p;
    loop(i, t.size()) {
        int x;
        cin >> x;
        p.push_back((x - 1));
    }

    int low = 0, high = t.size() - 1;
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(check(t, s, p, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans + 1 << '\n'; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
