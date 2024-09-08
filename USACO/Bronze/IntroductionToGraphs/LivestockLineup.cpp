#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    vector<string> a = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(range(a));
    unordered_map<string, int> cow;
    for(int i = 0; i < 8; i++) {
        cow[a[i]] = i;
    }
    cin >> n;

    vector<int> adj[8];
    for(int i = 1; i <= n; i++) {
        string cow1, cow2, extra;
        cin >> cow1 >> extra >> extra >> extra >> extra >> cow2;
        // cout << "cow1: " << cow1 << "-> " << cow[cow1] << " cow2: " << cow2 << "-> " << cow[cow2] << "\n";
        adj[cow[cow1]].push_back(cow[cow2]);
        adj[cow[cow2]].push_back(cow[cow1]);
    }

    vector<bool> visited(8, false);
    vector<int> ans;
    
    for(int i = 0; i < 8; i++) {
        if(!visited[i] && adj[i].size() <= 1) {
            visited[i] = true;
            ans.push_back(i);

            if(adj[i].size() == 1) {
                int prev = i;
                int curr = adj[i][0];

                while(adj[curr].size() == 2) {
                    visited[curr] = true;
                    ans.push_back(curr);

                    int a = adj[curr][0];
                    int b = adj[curr][1];

                    int temp = prev == a? b: a;
                    prev = curr;
                    curr = temp;
                }
                visited[curr] = true;
                ans.push_back(curr);
            }
        }
    }

    for(auto x: ans) {
        cout << a[x] << "\n";
    }
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
