#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a;

bool allEqual(vector<int> &a) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            return false;
        }
    }
    return true;
}

/* My mind During contest:
    1. First mistake was not to read question carefully, didn't see the word to minimise the length
    2. Second thought : 2 pointers, then discarded
    3. Made question even complex
    4. Then, thought to find the largest subarray with length == distinct element in that subarray, not distint element
    5. I thought then we can't maximise the answer
    6. Thought we need to satisfy two conditions : (4) and all the element in that subarray should be distinct
    7. Then concluded that find the subarray with longest length having only distinct element
    8. But it's not working
*/ 


void solve() {
    cin >> n;
    a.resize(n);
    map<int, int> mp;
    for (auto &x: a) {
        cin >> x;
        mp[x]++;
    }


    for (auto &x: a) {
        if (mp[x] == 1) {
            x = 1;
        }
        else {
            x = 0;
        }
    }

    int left = -1, right = -1, maxLen = INT_MIN, freq = 0;

    for (int i = 0; i < n; ) {
        if (a[i] == 1) {
            int j = i;
            while (j < n && a[j] == 1) {
                j++;
            }
            if (maxLen <= j - i) {
                left = i, right = j - 1;
            }
            i = j;
        }
        else {
            i++;
        }
    }

    if (left == right && left == -1) {
        cout << 0 << "\n";
        return;
    }
    
    cout << left + 1 << " " << right + 1 << "\n";
}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}