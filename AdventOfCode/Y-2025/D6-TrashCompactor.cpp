#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

pair<vector<vector<ll> >, vector<char> > take_input() {
    string s;
    vector<string> a;

    while (cin >> s) {
        a.push_back(s);
    }
    int n = 0;

    vector<char> ops;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == "*" || a[i] == "+") {
            n++;
            ops.push_back(a[i][0]);
        } else {
            break;
        }
    }
    reverse(range(ops));
    
    vector<vector<ll> > nums;

    for (int i = 0; i < a.size() - 1; i += n) {
        if (a[i] == "*" || a[i] == "+") 
            break;

        vector<ll> temp;
        for (int j = i; j < i + n; j++) {
            temp.push_back(stoll(a[j]));
        }
        nums.push_back(temp);
        
    }

    return make_pair(nums, ops);
}   

ll add(ll a, ll b) {
    return a + b;
} 

ll mul(ll a, ll b) {
    return (ll)a * b;
}


void solve_part_1() {
    auto p = take_input();

    auto nums = p.first;
    auto ops = p.second;

    int n = nums.size(), m = nums[0].size();
  
    ll ans = 0;

 

    for (int i = 0; i < m; i++) {
        ll tmp = ops[i] == '+' ? 0 : 1;
        ll (*fun)(ll, ll);

        fun = (ops[i] == '+' ? add : mul);
        
        for (int j = 0; j < n; j++) {
            tmp = fun(tmp, nums[j][i]);
        }
        
        ans += tmp;
    }

    cout << ans << "\n";
}   


void solve_part_2() {
    string s;
    vector<string> a;

    while (getline(cin, s)) {
        a.push_back(s);
        
    }
    ll ans = 0;

    int n = a.size();
    int j = 0;
    
    while (true) {
        int i = j;
        j++;
        while (j < a[n - 1].size()) {
            if (a[n - 1][j] == '+' || a[n - 1][j] == '*')
                break;
            j++;
        }
        ll tmp = (a[n - 1][i] == '+' ? 0 : 1);

        ll (*fun)(ll, ll) = tmp ? mul : add;

        int k = j - (j == a[n - 1].size() ? 1 : 2);

        for (int p = k; p >= i; p--) {
            ll num = 0;
            for (int q = 0; q < n - 1; q++) {
                if (a[q][p] == ' ') 
                    continue;
                ll t = a[q][p] - '0';
                num = num * 10 + t;
            }

            tmp = fun(tmp, num);
        }

        ans += tmp;
        if (j == a[n - 1].size()) {
            break;
        }
    }

    cout << ans << "\n";

}



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif

    solve_part_2();
    return 0;
}