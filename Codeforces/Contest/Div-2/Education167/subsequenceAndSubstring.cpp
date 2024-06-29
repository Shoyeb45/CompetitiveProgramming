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


int maxLenSubsequence(string a, string b) {
    int mxLen = 0, subLength = 0;
    for(int i = 0; i < b.size(); i++) {
        int idx = i;
        subLength = 0;
        loop(j, a.size()) {
            if(a[j] == b[idx]) {
                idx++;
                subLength++;
            }
        }
        mxLen = max(mxLen, subLength);
    }
    return mxLen;
}
void solve() {
    string a, b;
    cin >> a >> b;
    int ans = a.size() + b.size();
    cout << ans - maxLenSubsequence(a, b) << '\n';
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
