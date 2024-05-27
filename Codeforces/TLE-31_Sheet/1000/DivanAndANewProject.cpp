#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// void solve() {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> a(n, {0, 0});
//     vector<int> coordinate(n + 1, 0);
//     loop(i, n) {
//         int x;
//         cin >> x;
//         a[i] = {x, i};
//     }

//     int k = 1;
//     for(int i = 1; i <= n; i++) {
//         if(i % 2) {
//             coordinate[i] = -k;
//         } else {
//             coordinate[i] = k;
//             k++;
//         }
//     }

//     sort(a.begin(), a.end());
//     reverse(a.begin(), a.end());

//     int min_time = 0;
//     for(int i = 1; i <= n; i++) {
//         min_time += (abs(coordinate[i]) * 2 * a[i - 1].first);
//     }
//     cout << min_time << '\n' << 0 << " ";

//     for(int i = 0; i < n; i++) {
//         cout << coordinate[a[i].second] << ' '; 
//     }
//     // loop(i, n + 1)
//     //     cout << coordinate[i] << ' ';
//     cout << '\n'; 
// }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n, {0, 0});
    loop(i, n) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    vector<int> coordinate(n);
    int k = 1;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll min_time = 0;
    loop(i, n) {
        if(i % 2 == 0) {
            coordinate[a[i].second] = k;
            min_time += (1LL * k * 1LL * a[i].first);
        } else {
            coordinate[a[i].second] = -k;
            min_time += (1LL * k * 1LL * a[i].first);
            k++;
        }
    }
    cout << min_time * 2 << "\n0 ";
    loop(i, n) {
        cout << coordinate[i] << ' ';
    }
    cout << '\n';
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
