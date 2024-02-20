#include<bits/stdc++.h>

using namespace std;

void swap(int a[], int l, int r) {
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if(n == 3) {
            for(int i=1; i<=3; i++) cout << i << " " ;
        } else {
                int a[n];
                for(int i=0; i<=n-1 ; i++) {
                    a[i] = i+1;
                }
                for(int i=0; i<=n-1 ; ) {
                    if(a[i] % 2 != 0 && i+2 <= n-1) {
                        swap(a, i, i+2);
                        i += 3;
                    } else {
                        i++;
                    }
            }

                for(int i=0; i<=n-1 ; i++) {
                    cout << a[i] << " " ;
                }
        }
        cout << "\n";
    }
    return 0;
}