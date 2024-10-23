#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
bool verdict(const std::string& p1, const std::string& p2) {
    std::ifstream f1(p1, std::ifstream::binary);
    std::ifstream f2(p2, std::ifstream::binary);

    // Check if both files were successfully opened
    if (!f1.is_open()) {
        std::cerr << "Failed to open file: " << p1 << "\n";
        return false;
    }
    if (!f2.is_open()) {
        std::cerr << "Failed to open file: " << p2 << "\n";
        return false;
    }

    // Compare the sizes of the files
    f1.seekg(0, std::ifstream::end);
    f2.seekg(0, std::ifstream::end);
    if (f1.tellg() != f2.tellg()) {
        return false;
    }

    // Reset file pointers to the beginning
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);

    // Compare contents
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

const ll mod = 1000000007;

int n;

int bfs(int start, vector<vector<bool>> &adj, vector<bool> &vis) {
    int ans = 1;
    queue<int> q;
    q.push(start);

    vis[start] = 1;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
           if(adj[curr][i] && !vis[i]) {
                vis[i] = 1;
                ans++;
                q.push(i);
           }
        }
    }
    return ans;
}

void solve() {
    cin >> n;

    vector<int> x(n), y(n), p(n);

    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }

    int i = 0, j = 0;
    vector<vector<bool>> canTransmit(n, vector<bool>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if(dist <= p[i] * p[i]) {
                canTransmit[i][j] = 1;
            }
        }
    }

    int ans = 1;
  

    for(int i = 0; i < n; i++) {
        vector<bool> vis(n, 0);
        ans = max(ans, bfs(i, canTransmit, vis));
    }
    cout << ans;
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    cerr << (verdict("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\verdict.out") ? "Correct Answer": "Incorrect Answer") << "\n";
    return 0;
}