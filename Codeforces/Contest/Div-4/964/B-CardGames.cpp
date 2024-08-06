#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int a1, a2, b1, b2;

int countSuneetWins() {
    vector<pair<int, int>> a = {{a1, a2}, {a2, a1}};
    vector<pair<int, int>> b = {{b1, b2}, {b2, b1}};

    int waysToWin = 0;

    for (auto suneet : a) {
        for (auto slavic : b) {
            int suneetWins = 0, slavicWins = 0;

            if (suneet.first > slavic.first) suneetWins++;
            if (slavic.first > suneet.first) slavicWins++;

            if (suneet.second > slavic.second) suneetWins++;
            if (slavic.second > suneet.second) slavicWins++;

            if (suneetWins > slavicWins) waysToWin++;
        }
    }

    return waysToWin;
}

void solve() {
    cin >> a1 >> a2 >> b1 >> b2;
    cout << countSuneetWins() << '\n';
}

int main() {
    NFS
    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
