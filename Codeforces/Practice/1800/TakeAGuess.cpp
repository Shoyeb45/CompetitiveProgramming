#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

int ask(string s, int i, int j) {
    cout << s << " " << i << " " << j << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int sum(int i, int j) {
    int AND = ask("and", i, j);
    int OR = ask("or", i, j);

    int XOR = ((~AND) & (OR));
    int ans = (AND << 1) + XOR;
    return ans;
}
int n, k;
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int a = sum(1, 2);
    int b = sum(2, 3);
    int c = sum(1, 3);

    vector<int> req_seq = {(c + a - b) / 2, (b - c + a) / 2, (c + b - a) / 2};

    for(int i = 3; i < n; i++) {
        int _sum = sum(i, i + 1);
        req_seq.push_back(_sum - req_seq[i - 1]);
    }

    // loop(i, n) {
    //     cout << req_seq[i] << " ";
    // }
    sort(range(req_seq));
    cout << "finish " << req_seq[k - 1] << '\n';
    cout.flush();
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
