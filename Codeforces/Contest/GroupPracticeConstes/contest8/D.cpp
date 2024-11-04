#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;
bool isUpperCase(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isLowerCase(char ch) {
    return ch >= 'a' && ch <= 'z';
}
void solve() {
    cin >> s;

    int n = s.size();
    vector<int> lower(n, -1), upper(n, -1);

    for(int i = 1; i < n; i++) {
        if(isUpperCase(s[i - 1])) {
            upper[i] = i - 1;
        }
        else {
            upper[i] = upper[i - 1];
        }

        if(isLowerCase(s[i - 1])) {
            lower[i] = i - 1;
        }
        else {
            lower[i] = lower[i - 1];
        }
    }

    vector<bool> mark(n, true);

    for(int i = 0; i < n; i++) {
        if(s[i] == 'B') {
            mark[i] = false;
            int temp = upper[i];
            if(temp == -1 || mark[temp] == false) {
                while(temp != -1) {
                    
                }
            } 
        }
        else if(s[i] == 'b') {
            mark[i] = false;
            int temp = i;
            while(lower[temp] != -1) {
                temp = lower[temp];
            }
            mark[temp] = false;
        }
        
    }

    for(int i = 0; i < n; i++) {
        if(mark[i]) {
            cout << s[i];
        }
    }
    cout << "\n";
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