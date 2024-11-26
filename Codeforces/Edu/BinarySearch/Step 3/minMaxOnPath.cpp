#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, d;
class Edge {
public:
    int from, to, weight;
};

std::vector<Edge> edges;
vector<vector<pair<int, int>>> adj;

bool bfs(vector<int> &res, ll mid) {
    queue< pair < int, int >> q;
    q.push({1, 0});
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth > d) {
            continue;
        }

        if (curr == n) {
            res.clear();
            while (curr != -1) {
                res.push_back(curr);
                curr = parent[curr];
            }
            sort(res.begin(), res.end());
            return true;
        }

        for (auto node : adj[curr]) {
            if (dist[node.first] > depth + 1) {
                dist[node.first] = depth + 1;
                parent[node.first] = curr;
                q.push({node.first, depth + 1});
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> d;

    edges.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        if (edges[i].from > edges[i].to) {
            swap(edges[i].from, edges[i].to);
        }
    }

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){ 
        return a.weight < b.weight; 
    });

    ll low = 0, high = 1e9;
    adj.resize(n + 1);
    vector<int> mainAns;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }

        for (auto edge : edges) {
            if (edge.weight <= mid) {
                adj[edge.from].push_back(make_pair(edge.to, edge.weight));
            }
        }

        vector<int> ans;
        if (bfs(ans, mid)) {
            high = mid - 1;
            mainAns = ans;
        }
        else {
            low = mid + 1;
        }
    }

    if (mainAns.empty()) {
        cout << -1 << "\n";
    }
    else {
        cout << mainAns.size() - 1 << "\n";
        for (auto x : mainAns) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}