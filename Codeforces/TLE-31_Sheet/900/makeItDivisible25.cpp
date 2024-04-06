#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)  
using namespace std;
typedef long long ll;
 

void solve(ll n) {
    string s = to_string(n);
    int ans = INT_MAX;
    int t = s.size();
    loop(i, s.size()) {
        for(int j = i + 1; j < s.size(); j++) {
            int check = (s[i] - '0') * 10 + (s[j] - '0');
            if(check % 25 == 0) {
                ans = min(ans, (j - i - 1) + (t - 1 - j));
            }
        }
    }

    cout << ans << endl;
}

// void solve2(ll n) {
//     string s = to_string(n);
//     // vector<pair<int,int>> vp;

//     int ans = INT_MAX;
//     loop(i, s.size() - 1) {
//         for(int j = i + 1; j < s.size(); j++) {

//             int check = (s[i] - '0') * 10 + (s[j] - '0');
//             if(check % 25 == 0) {
//                 ans = min(ans,  (j - i - 1) + (s.size() - i - 1));
//                 // vp.push_back(make_pair(i, j));
//             }
//         }
//     }
    // sort(vp.begin(), vp.end(), compareSecond);
    // loop(i, vp.size()) {
    //     int step = (vp[i].second - vp[i].first - 1) + (s.size() - vp[i].second - 1);
    //     ans = min(ans, step);
    // }
//     cout << ans << endl;
//     return;
// }

// void solve1(ll n) {
//     string s = to_string(n);
//     int ind0 = 0, ind5 = 0;

//     loop(i, s.size()) {
//         if(i >= 1 && s[i] == '0' && s[i-1] == '0')   ind0 = max(ind0, i);
//         if(s[i] == '5') {
//             if(i >= 1) {
//                 int x = s[i - 1] - '0';
//                 int check = x * 10 + (s[i] - '0');
//                 ind5 = max(ind5, check % 25 == 0? i: 0);
//             }
//             if(i <= s.size() - 2) {
//                 ind5 = max(ind5, s[i + 1] == '0' ? i + 1: 0);
//             }
//         }
//     }
//     int ans = max(ind0, ind5);

//     if(ans == 0) {
//         solve2(n);
//         return;
//     }

//     cout << s.size() - 1 - ans << endl;
    
// }


int main() {
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if(n % 25 == 0)  cout << 0 << "\n";
        else {
            solve(n);
        }
    }
}