#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

// My First solution: It was using dp, but due to cycle it will go into infinite loop.
// That solution can work on DAG or Tree
// and if we use visited array, then it will not reach all the path.


// State, for Djikstra, here we are using state, we'll update the state while computing the
// minimum cost. This is called graph modelling.
class State {
public:
    // is_discount_taken -> 1 means we used the coupon
    int v, is_discount_taken;
    ll dist;

    State(int v, ll dist, int is_discount_taken) {
        this->v = v, this->is_discount_taken = is_discount_taken, this->dist = dist;
    }

    bool operator>(const State &s) const {
        return dist > s.dist;
    }
};

int n, m;
vector<vector<pair<int, ll>>> adj;

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);

    while (m--) {
        int a, b; 
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(State(1, 0, 0));

    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    dist[1][0] = 0;
    dist[1][1] = 0;

    while (!pq.empty()) {
        State p = pq.top();
        ll d = p.dist;
        pq.pop();
        
        if (p.dist > dist[p.v][p.is_discount_taken]) {
            continue;
        }

        for (auto x: adj[p.v]) {
            int v = x.first;
            ll w = x.second;

            if (p.is_discount_taken && d + w < dist[v][1]) {
                dist[v][1] = d + w;
                pq.push(State(v, dist[v][1], 1));
            } else if (!p.is_discount_taken) {

                if (d + w < dist[v][0]) {
                    dist[v][0] = d + w;
                    pq.push(State(v, dist[v][0], 0));
                }

                if ((d + w / 2) < dist[v][1]) {
                    dist[v][1] = (d + w / 2);
                    pq.push(State(v, dist[v][1], 1));
                }
            }
        }
    }
    // Take minimum of both two q
    cout << min(dist[n][0], dist[n][1]) << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}