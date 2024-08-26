#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;

    loop(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int turtleTurn, piggyTurns;
    piggyTurns = turtleTurn = n / 2;
    if(n % 2 == 0) {
        piggyTurns -= 1;
    } 

    // cout << turtleTurn << '\n';
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(turtleTurn > 0) {
            if(it -> second <= turtleTurn) {
                turtleTurn -= it -> second;
                it -> second = 0;
            } else {
                it -> second -= turtleTurn;
                turtleTurn = 0;
                break;
            }
        }
    }

    for(auto it = mp.rbegin(); it != mp.rend(); it++) {
        if(piggyTurns > 0) {
            if(it -> second <= piggyTurns) {
                piggyTurns -= it -> second;
                it -> second = 0;
            } else {
                it -> second -= piggyTurns;
                piggyTurns = 0;
                break;
            }
        }
    }

    for(auto it : mp) {
        if(it.second != 0) {
            cout << it.first << '\n';
            return;
        }
    }
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
