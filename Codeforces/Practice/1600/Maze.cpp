#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;
vector<vector<char>> a;
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    cin >> n >> m >> k;
    int x = 0, y = 0;
    a.resize(n, vector<char>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '.') {
                x = i, y = j;  // Store any index with non-empty cell to traverse
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false)); // Maintain visited array to visit any node only once
    queue<pair<int, int>> q;
    q.push({x, y}); // Start from stored index
    vis[x][y] = 1;
    vector<pair<int, int>> ans = {{x, y}}; // Vector to store the indices

    while(!q.empty()) {
        auto pt = q.front();
        q.pop();

        // Check all the four sides
        for(int k = 0; k < 4; k++) {
            int nx = dx[k] + pt.first, ny = dy[k] + pt.second; 
            pair<int, int> curr = {nx, ny}; // New Index

            // Check if the index is valid and can we visit it
            if(nx >= 0 && ny >= 0 && nx < n && ny < m  && a[nx][ny] == '.' && !vis[nx][ny]) {
                ans.push_back({nx, ny}); // Push the index in our array
                vis[nx][ny] = 1;         // Mark the visited array 
                q.push(curr);            // Push in the queue
            }
        }
    }

    // Assign 'X' to the last k cells
    for(int i = ans.size() - k; i < ans.size(); i++) {  
        a[ans[i].first][ans[i].second] = 'X';
    }

    // Print the given grid
    for(auto vec: a) {
        for(char ch: vec) {
            cout << ch;
        }
        cout << "\n";
    }

}   

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}