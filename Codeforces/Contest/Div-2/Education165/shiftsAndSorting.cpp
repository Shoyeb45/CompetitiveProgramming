#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    string s;
    cin >> s;
    ll cost = 0;
    int one = 0;
    vector<int> zeroes;
    vector<int> ones;
    
    int start = 0;
    int end = s.size() - 1;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            start = i;
            break;
        }
    }

    for(int i = s.size() - 1; i >= 0 ; i--) {
        if(s[i] == '0') {
            end = i;
            break;
        }
    }
    for(int i = start; i <= end; ) {
        if(s[i] == '1' ) { 
            while(i < s.size() && s[i] == '1') {
                i++;
                one++;
            }
            ones.push_back(one);
        } else {
            int zero = 0;
            while(i < s.size() && s[i] == '0') {
                i++;
                zero++;
            }
            zeroes.push_back(zero);
        }
    }

    if(ones.size() == 0 || zeroes.size() == 0) {
        cout << 0 << '\n';
        return;
    }

    for(int i = 0; i < ones.size(); i++) {
        cost += ((ones[i] + 1) * zeroes[i]);
    }

    cout << cost << '\n';
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
