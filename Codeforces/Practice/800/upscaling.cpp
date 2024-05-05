#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 0) {
                for(int j = 1; j <= n; j++) {
                    if(j % 2 == 0) cout << "##";
                    else    cout << "..";
                }
                cout << "\n";
                for(int j = 1; j <= n; j++) {
                    if(j % 2 == 0) cout << "##";
                    else    cout << "..";
                }
                cout << "\n";
                
            } else {
                for(int j = 1; j <= n; j++) {
                    if(j % 2 == 1) cout << "##";
                    else    cout << "..";
                }
                cout << "\n";
                for(int j = 1; j <= n; j++) {
                    if(j % 2 == 1) cout << "##";
                    else    cout << "..";
                }
                cout << "\n";
            }
        }
    }
    
}
