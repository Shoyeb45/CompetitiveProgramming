#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<pair<ll, int>> a;

int bs(ll target, int high) {
    if(high < 0) {
        return -1;
    }
    int low = 0;
    int ans = -1;
    while(low <= high) {
        int mid = (high + low) / 2;

        if(a[mid].first <= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    vector<ll> pref(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(range(a));
    for(int i = 0; i < n; i++) {
        pref[i + 1] += pref[i] + a[i].first;
    }
    reverse(range(a));
    reverse(range(pref));
 
    vector<ll> ans(n);

    for(int i = 0; i < n; i++) {
        ll currAns = n - i - 1;
        ll score = pref[i];
        if(i == 0) {
            ans[a[i].second] = currAns;
            continue;
        }

        int j = bs(score, i - 1);
        int tempInd = i;
        while(j != -1) {
            currAns += tempInd - j;
            score = pref[j];
            tempInd = j;
            j = bs(score, j - 1);
        }
        ans[a[i].second] = currAns;
    } 

    for(auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
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