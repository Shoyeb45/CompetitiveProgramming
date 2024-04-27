#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>> A(n, vector<char>(n, 0));
    vector<vector<char>> B(n, vector<char>(n, 0));

    loop(i, n) {
        loop(j, n) {
            cin >> A[i][j];
        }
    }    
    loop(i, n) {
        loop(j, n) {
            cin >> B[i][j];
        }
    }    

    int iIdx = 0, jIdx = 0;
    loop(i, n) {
        loop(j, n) {
            if(A[i][j] != B[i][j]) {
                iIdx = i;
                jIdx = j;
            }
        }
    }    

    cout << iIdx + 1 << " " << jIdx + 1 << endl;

    return 0;
}
