#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s, t;
void solve() {
    cin >> s >> t;

    vector<int> ans;
    vector<int> idx;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != t[i]) {
            idx.push_back(i);
        }
    }
    sort(idx.begin(), idx.end());
    vector<bool> mark(idx.size(), false);

    cout << idx.size() << "\n";
    while (count(range(mark), true) != idx.size()) {
        for (int i = 0; i < idx.size(); i++) {
            if (!mark[i]) {
                if (s[idx[i]] > t[idx[i]]) {
                    s[idx[i]] = t[idx[i]];
                    mark[i] = true;
                }
                else {
                    bool atLeastOne = false;
                    for(int j = i + 1; j < idx.size(); j++) {
                        if(s[idx[j]] > t[idx[j]]) {
                            s[idx[j]] = t[idx[j]];
                            mark[j] = atLeastOne = true;
                            break;
                        }
                    }

                    if (!atLeastOne) {
                        for(int j = idx.size() - 1; j >= 0; j--) {
                            if(!mark[j]) {
                                s[idx[j]] = t[idx[j]];
                                mark[j] = true;
                                break;
                            }
                        }
                    }
                }
                cout << s << "\n";
            }
        }
    }
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