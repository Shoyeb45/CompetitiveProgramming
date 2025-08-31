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


void solve() {
    string s;
    cin >> s;

    int left_won = 0, right_won = 0, left_pt = 0, right_pt = 0, current_serve = 0;
    // 0 -> left, 1 -> right


    auto check_winner = [&]() {
        if (abs(left_pt - right_pt) >= 2 && (left_pt >= 5 || right_pt >= 5)) {
            if (left_pt >= 5) {
                left_won++; 
            } else if (right_pt >= 5) {
                right_won++;
            }
            left_pt = 0, right_pt = 0;
        }
        if (left_pt >= 10) {
            left_won++;
            left_pt = 0, right_pt = 0;
        }

        if (right_pt >= 10) {
            right_won++;
            left_pt = 0, right_pt = 0;
        }
    };

    auto winner_announce = [&]() {
        if (left_won > right_won) {
            cout << left_won << " " << "(winner)" << " - " << right_won << "\n";
        }
        if (right_won > left_won) {
            cout << left_won << " - " << right_won << " (winner)\n";  
        }
    };

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == 'Q') {
            if (i == s.size() - 1) {
                winner_announce();
            } else {
                cout << left_won << " (" << left_pt << (current_serve == 0? "*": "") << ") - " << right_won << " (" << right_pt << (current_serve == 1? "*": "") << ")\n";
            }
        } else if (ch == 'R') {
            if (current_serve == 0) {
                right_pt++;
                current_serve = 1;
            } else {
                left_pt++;
                current_serve = 0;
            }
            check_winner();
        } else {
            if (current_serve == 0) {
                left_pt++;
            } else {
                right_pt++;
            }
            check_winner();
        }   
    }

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
