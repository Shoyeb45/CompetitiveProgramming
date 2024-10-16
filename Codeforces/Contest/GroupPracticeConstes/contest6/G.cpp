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
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    int skip = 0;
    int i = 0, j = 0;
    bool friendTurn = 1;
    while(i < n && j < n) {
        if(friendTurn) {
            if(a[i] == 1) {
                skip++;
                i++;
                if(i < n && a[i] == 0) {
                    i++;
                }
                else {
                    i--;
                }
            } 
            else {
                i++;
                if(i < n && a[i] == 0) {
                    i++;
                }
                else {
                    i--;
                }
            }
            j = i + 1;
            friendTurn = 0;
        }
        else {
            i = j + 2;
            friendTurn = 1;
        }
    }
    cout << skip << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}