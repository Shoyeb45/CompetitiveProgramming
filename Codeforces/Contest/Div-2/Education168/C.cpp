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


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    set<int> st;
    for(int i = 0; i < n; i += 2) {
        st.insert(i);
    }

    for(int i = 1; i < n; i += 2) {
        if(s[i] == ')') {
            int idx = i - 1;
            if(st.find(idx) != st.end()) {
                ans += 1;
                st.erase(st.find(idx));
            } else {
                int b = *st.begin();
                ans += (i - b);
                st.erase(st.begin());
            }
        } else {
            int idx = i + 1;
            if(st.find(idx) != st.end()) {
                ans += 1;
                st.erase(st.find(idx));
            }
        }
    }
    cout << ans << '\n';
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
