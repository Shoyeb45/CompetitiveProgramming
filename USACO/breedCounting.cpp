#include <iostream>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;

    int que[N] = {0};
    for (int i = 0; i < N; i++) {
        cin >> que[i];
    }

    int arr[N][3] = {0};

    for (int i = 0; i < N; i++) {
        int idx = que[i] - 1;
        if (idx >= 0 && idx < 3) {
            arr[i][idx]++;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] += arr[i - 1][j];
        }
    }

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans[3] = {0};
        for (int i = 0; i < 3; i++) {
            ans[i] = arr[r][i];
            if (l > 0) {
                ans[i] -= arr[l - 1][i];
            }
        }

        for (int i = 0; i < 3; i++) {
            if(i == 2) {
                cout << ans[i];
                break;    
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}