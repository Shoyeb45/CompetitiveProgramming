#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
string s;

bool completedMap(unordered_map<char, int> mp) {
    for(auto it : mp) {
        if(it.second != 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n >> s;

    unordered_map<char, int> mp;

    for(auto ch: s) {
        mp[ch]++;
    }

    while(true) {
        if(completedMap(mp)) {
            break;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it ->second > 0) {
                cout << it -> first;
                it -> second--;
            }
        }
    }
    cout << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
