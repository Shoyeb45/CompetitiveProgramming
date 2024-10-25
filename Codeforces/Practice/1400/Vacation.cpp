#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int n;
vector<bool> gym, contest;

void solve() {
    cin >> n;
    gym.resize(n), contest.resize(n);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            gym[i] = contest[i] = 0;
        }
        else if(x == 1) {
            gym[i] = 0;
            contest[i] = 1;
        }
        else if(x == 2) {
            gym[i] = 1;
            contest[i] = 0;
        }
        else {
            gym[i] = contest[i] = 1;
        }
    }     

    bool isContest = 0, isGym = 0;

    ll abs = 0;
    
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}