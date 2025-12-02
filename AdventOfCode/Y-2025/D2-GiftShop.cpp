#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


bool is_invalid_id_2(string s) {
    int n = s.size();

    // 1234123
    bool ok = false;
    for (int i = 0; i < n / 2; i++) {
        string tmp = s.substr(0, i +1);
        bool ok2 = true;
        for (int j = 0; j < n; j += tmp.size()) {
            string t = s.substr(j, tmp.size());
            if (t != tmp) {
                ok2 = false;
                break;
            }
        }
        if (ok2) {
            ok = true;
            break;
        }
    }
    return ok;
}

bool is_invalid_id_1(string s) {
    int n = s.size();
    if ((n & 1)) return false;
    string first_half = s.substr(0, n / 2);
    string second_half = s.substr(n / 2);
  
    return first_half == second_half;
}

void solve() {
    string s;
    cin >> s;
    vector<string> all_inter;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            all_inter.push_back(temp);
            temp = "";
            continue;
        }
        temp += s[i];
    }

    if (temp != "") {
        all_inter.push_back(temp);
    }

    ll sum = 0;
    set<ll> valids;

    for (auto &x: all_inter) {
        ll x1, x2;
        cout << x << "\n";
        int i = x.find('-');
        x1 = stoll(x.substr(0, i));
        x2 = stoll(x.substr(i + 1));

        for (ll i = x1; i <= x2; i++) {
            if (valids.count(i)) continue;

            // if (is_invalid_id_1(to_string(i))) { // part1
            if (is_invalid_id_2(to_string(i))) { // part2
                sum += i;
            } else {
                valids.insert(i);
            }
        }
    }

    cout  << sum << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}