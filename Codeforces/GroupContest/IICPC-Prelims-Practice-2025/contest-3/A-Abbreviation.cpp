#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string find_ans(string &s) {
    int n = s.size();
    string ans = "";

    auto valid_word = [&](int i, int j) -> bool {
        // cout << i <<  " " << j << "\n";
        if (j == i) {
            return false;
        }
        for (int k = i + 1; k <= j; k++) {
            if (s[k] >= 'a' && s[k] <= 'z') {
                continue;
            }
            return false;
        }
        return true;
    };
    auto valid = [&](string &s) -> bool {
        if (s.size() == 1) {
            return false;
        }
        for (int k = 1; k < s.size(); k++) {
            if (s[k] >= 'A' && s[k] <= 'Z') {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        if ((i - 1 < 0 || s[i - 1] == ' ' || s[i - 1] == '.' || s[i - 1] == ',') && (s[i] >= 'A' && s[i] <= 'Z')) {
            vector<string> words;
            string  word = "";
            string abbr = "";
            string bad = "";
            int space_count = 0;
            
            int idx = i;
            int j = i;
            // let's form abbrevation
            for (; j < n; j++) {
                if (space_count >= 2) {
                    break;
                }
                
                if ((j - 1 < 0 || s[j - 1] == ' ' || s[j - 1] == '.' || s[j - 1] == ',') && (s[j] >= 'A' && s[j] <= 'Z')) {
                    word += s[j];
                    abbr += s[j];
                    idx = j;
                } else if (s[j] == ' ') {

                    if (!valid_word(idx, j - 1)) {
                        bad = word;
                        word = "";
                        if (!abbr.empty()) {
                            abbr.pop_back();
                        }
                        break;
                    }
                    // debug("word", word);
                    words.push_back(word);
                    space_count = 0;
                    while (j < n && s[j] == ' ') {
                        j++;
                        space_count++;
                    }
                    j--;
                    word = "";
                } else if (s[j] == ',' || s[j] == '.') {
                    if (s[j - 1] == ' ') {
                        break;
                    }
                    if (!valid_word(idx, j - 1)) {
                        bad = word;
                        word = "";
                        if (!abbr.empty()) {
                            abbr.pop_back();
                        }
                        break;
                    }
                    // debug("word", word);
                    space_count = 0;
                    words.push_back(word);
                    word = "";
                    break;
                }
                else {
                    if (s[j - 1] == ' ') {
                        space_count = 0;
                        int k = j - 1;
                        while (k >= i && s[k] == ' ') {
                            k--;
                            space_count++;
                        }
                        break;
                    }
                    word += s[j];
                }
            } 
            
            if (!word.empty() && !valid(word)) {
                if (!abbr.empty()) {
                    abbr.pop_back();
                }
                bad = word;
                word = "";
            } 
            
            if (j >= n && bad.size() == 0) {
                // debug("bad", bad.size());
                space_count = 0;
            }
            if (word != "") {
                words.push_back(word);            
            }

         
            
            if (words.size() > 1) {
                string ff = "";
                for (int k = 0; k < words.size(); k++) {
                    ff += words[k];
                    if (k != words.size() - 1) {
                        ff += " "; 
                    }
                }
                ans += abbr + " (" + ff + ")";
                while (space_count--) {
                    ans += " ";
                }
            } else {
                if (!words.empty()) {
                    ans += words[0];
                }
                while (space_count--) {
                    ans += " ";
                }
            }
            
            if (bad != "") {
                ans += bad;
                while (space_count-- > 0) {
                    ans += " ";
                }
            }
            
         
            i = j - 1;
        } else if (s[i] == ' ') {
            ans += s[i];
        } else {
            // cout << s[i] << ", ";
            ans += s[i];
        }
    }
    return ans;
}
void solve() {
    string t;
    vector<string> a;
    while (getline(cin, t)) {
        a.push_back(t);
    }

    for (int i = 0; i < a.size(); i++) {
        string s = a[i];
        cout << find_ans(s);
        if (i != a.size() - 1) {
            cout << "\n";
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
    // freopen("abbreviation.in", "r", stdin);
    // freopen("abbreviation.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}