#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<string> cows[30];
bool check(int A, int B, vector<string> &allChars) {
    bool aNotB = 0, bNotA = 0, aAndB = 0;

    for(int i = 0; i < n; i++) {
        bool hasA = 0, hasB = 0;
        for(auto chars: cows[i]) {
            if(chars == allChars[A]) {
                hasA = 1;
            }
            if(chars == allChars[B]) {
                hasB = 1;
            }
        }

        if(hasA && !hasB) {
            aNotB = 1;
        }
        if(!hasA && hasB) {
            bNotA = 1;
        }
        if(hasA && hasB) {
            aAndB = 1;
        }
    }
    if(aNotB && bNotA && aAndB) {
        return false;
    }
    return true;
}

void solve() {
    cin >> n;

    set<string> allCharacteristics;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for(int j = 0; j < k; j++) {
            string s;
            cin >> s;
            cows[i].push_back(s);
            allCharacteristics.insert(s);
        }
    }

    vector<string> allChars(range(allCharacteristics));
    for(int i = 0; i < allChars.size(); i++) {
        for(int j = i + 1; j < allChars.size(); j++) {
            if(!check(i, j, allChars)) {
                cout << "no\n";
                return;
            }
        }
    }

    cout << "yes\n";
}

int main() {
    NFS
 
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}