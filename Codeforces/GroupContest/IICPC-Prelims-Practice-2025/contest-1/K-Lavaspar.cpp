#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


bool is_anagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    sort(range(s));
    sort(range(t));

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}


void solve() {
    int l, c;
    cin >> l >> c;

    vector<vector<set<int>>> ans(l, vector<set<int>>(c));
    unordered_map<char, vector<pair<int, int>> > char_ind;

    vector<string> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
        for (int j = 0; j < c; j++) {
            char_ind[a[i][j]].push_back({i, j});
        }
    }
    int n;
    cin >> n;
    
    vector<string> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    for (int x = 0; x < l; x++) {
        for (int y = 0; y < c; y++) {
            
            for (int wordIdx = 0; wordIdx < n; wordIdx++) {
                string word = temp[wordIdx];
                int len = word.length();
                
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
                
                for (int dir = 0; dir < 8; dir++) {
                    int nx = x + dx[dir] * (len - 1);
                    int ny = y + dy[dir] * (len - 1);
                    
                    if (nx < 0 || nx >= l || ny < 0 || ny >= c) continue;
                    
                    string extracted = "";
                    for (int k = 0; k < len; k++) {
                        extracted += a[x + dx[dir] * k][y + dy[dir] * k];
                    }
                    
                    if (is_anagram(word, extracted)) {
                        for (int k = 0; k < len; k++) {
                            ans[x + dx[dir] * k][y + dy[dir] * k].insert(wordIdx);
                        }
                    }
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (ans[i][j].size() >= 2) {
                count++;
            }
        }
    }
    cout << count << "\n";

}
int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
