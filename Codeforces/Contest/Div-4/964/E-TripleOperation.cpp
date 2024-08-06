#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;
const int MAX_N = 2e5; // Adjust based on constraints
vector<int> steps(MAX_N + 1, 0);

void precomputeSteps() {
    for (int i = 1; i <= MAX_N; i++) {
        int num = i;
        while (num != 0) {
            num /= 3;
            steps[i]++;
        }
    }
}

// int numOfSteps(int l) {
//     int ans = 0;
//     while(l != 0) {
//         l /= 3;
//         ans++;
//     }
//     return ans;
// }
void solve() {
    int l, r;
    cin >> l >> r;  

    int ans = steps[l];
    ans = 2 * ans + steps[l + 1];
    for(int i = l + 2; i <= r; i++) {
        ans += steps[i];
    }
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;
    precomputeSteps();
    while (tt--) {
        solve();
    }
    
    return 0;
}
