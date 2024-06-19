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

class Query {
    public:
    ll time;
    ll duration;
    int idx;

    Query() {
        time = 0;
        duration = 0;
        idx = 0;
    }

    void make_triplet(ll t, ll d, int i) {
        time = t;
        duration = d;
        idx = i;
    }
};

ll n, b;
vector<Query> a;

void solve() {
    cin >> n >> b;
    a.resize(n);

    loop(i, n) {
        ll t, d;
        cin >> t >> d;
        a[i].make_triplet(t, d, i);
    }

    vector<ll> ans(n);
    ll init_val = a[0].time;

    queue<Query> q;
    loop(i, n) {
        while(!q.empty() && a[i].time >= init_val + q.front().duration) {
            init_val += q.front().duration;
            ans[q.front().idx] = init_val;
            q.pop();
            if(!q.empty() && q.front().time > init_val) {
                init_val = q.front().time;
            } else if(q.empty() && a[i].time > init_val) {
                init_val = a[i].time;
            }
        }

        if(q.empty()) {
            q.push(a[i]);
        } else if(q.size() - 1 < b) {
            q.push(a[i]);
        } else {
            ans[a[i].idx] = -1;
        }
    }

    while(!q.empty()) {
        init_val += q.front().duration;
        ans[q.front().idx] = init_val;
        q.pop();
    }
    

    loop(i, n) 
        cout << ans[i] << ' ';
    cout << '\n';
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
