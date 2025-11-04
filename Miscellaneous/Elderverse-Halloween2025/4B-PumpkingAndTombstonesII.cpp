#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000009LL;

vector<vector<ll>> matmul(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = (int)A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (!A[i][k]) continue;
            ll aik = A[i][k];
            for (int j = 0; j < n; ++j) {
                C[i][j] += aik * B[k][j];
                if (C[i][j] >= (1LL<<62)) C[i][j] %= MOD; // avoid overflow, reduce occasionally
            }
        }
        for (int j = 0; j < n; ++j) C[i][j] %= MOD;
    }
    return C;
}

vector<vector<ll>> matpow(vector<vector<ll>> A, int p) {
    int n = (int)A.size();
    vector<vector<ll>> R(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) R[i][i] = 1;
    while (p > 0) {
        if (p & 1) R = matmul(R, A);
        A = matmul(A, A);
        p >>= 1;
    }
    return R;
}

// Build adjacency matrix for pumpkin types (E eyes, M mouths).
// vertex id = eye * M + mouth
vector<vector<ll>> build_adj(int E, int M) {
    int V = E * M;
    vector<vector<ll>> A(V, vector<ll>(V, 0));
    for (int e1 = 0; e1 < E; ++e1) {
        for (int m1 = 0; m1 < M; ++m1) {
            int u = e1 * M + m1;
            for (int e2 = 0; e2 < E; ++e2) {
                for (int m2 = 0; m2 < M; ++m2) {
                    int v = e2 * M + m2;
                    if (e1 == e2 || m1 == m2) A[u][v] = 1;
                }
            }
        }
    }
    return A;
}

// count number of valid pumpkin sequences of length L
ll count_segment_len(int L, int E, int M, const vector<vector<ll>>& adj) {
    int V = E * M;
    if (L == 0) return 1;       // empty segment
    if (L == 1) return V % MOD; // any single pumpkin
    // sequences of length L correspond to walks of length L-1 in graph
    vector<vector<ll>> Ap = matpow(adj, L - 1);
    ll total = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            total += Ap[i][j];
            if (total >= (1LL<<62)) total %= MOD;
        }
    }
    return total % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N, K, E, M;
        cin >> N >> K >> E >> M;
        int P = N - K; // number of pumpkins
        ll answer = 0;

        // Quick checks:
        // If K==0 -> single pumpkin segment of length P
        // If K >= 1, internal (K-1) segments must be >=1 each => need P >= K-1
        if (P < 0) {
            answer = 0;
        } else if (K == 0) {
            // Build adjacency and compute count(P)
            auto adj = build_adj(E, M);
            answer = count_segment_len(P, E, M, adj) % MOD;
        } else {
            if (P < K - 1) {
                answer = 0;
            } else {
                // Precompute segment counts for lengths 0..P
                auto adj = build_adj(E, M);
                vector<ll> cnt(P + 1);
                for (int L = 0; L <= P; ++L) cnt[L] = count_segment_len(L, E, M, adj);

                // DP over segments: there are (K+1) segments s0..sK
                // s0 and sK (ends) have min 0, internal s1..s_{K-1} have min 1
                int S = K + 1;
                // dp[i][j] = ways to fill first i segments (0..i-1) using j pumpkins
                vector<vector<ll>> dp(S + 1, vector<ll>(P + 1, 0));
                dp[0][0] = 1;
                for (int i = 1; i <= S; ++i) {
                    for (int used = 0; used <= P; ++used) {
                        if (dp[i-1][used] == 0) continue;
                        int minL = (i == 1 || i == S) ? 0 : 1; // segment index i-1: ends if i==1 or i==S
                        for (int L = minL; used + L <= P; ++L) {
                            dp[i][used + L] = (dp[i][used + L] + dp[i-1][used] * cnt[L]) % MOD;
                        }
                    }
                }
                answer = dp[S][P] % MOD;
            }
        }

        cout << "Case #" << tc << ": " << (answer % MOD + MOD) % MOD << '\n';
    }
    return 0;
}
