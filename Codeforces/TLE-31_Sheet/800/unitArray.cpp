#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0, prod = 1, negativeNo = 0;
        for (int i = 0 ; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            prod *= a[i];

            negativeNo += (a[i] < 0);
        }

        if((sum >= 0 && prod == 1) || (negativeNo == 0))   cout << 0 << "\n";
        else {
            int positiveNo = n - negativeNo;

            if(n % 2 == 0) {
                if(negativeNo == n) {
                    if((n/2) % 2 == 0)  cout << n/2 << "\n";
                    else    cout << n/2 + 1 << "\n"; 
                } else {
                    if(negativeNo % 2 == 0) {
                        if(negativeNo <= positiveNo)    cout << 0 << "\n";
                        else cout << negativeNo - positiveNo << "\n";
                    } else {
                        if(negativeNo <= positiveNo)    cout << 1 << "\n";
                        else {
                            if(((negativeNo - positiveNo)/2) % 2 == 0) cout << (negativeNo - positiveNo)/2 + 1 << "\n";
                            else    cout << (negativeNo - positiveNo) << "\n";
                        }
                    }
                }
            } else {
                if(negativeNo == n) {
                    if((n/2) % 2 == 0)  cout << n/2 + 1<< "\n";
                    else    cout << n/2 + 2 << "\n"; 
                } else {
                    if(negativeNo % 2 == 0) {
                        if(negativeNo <= positiveNo)    cout << 0 << "\n";
                        else {
                           
                                for(int i = 0; ; i += 2) {
                                    negativeNo -= 2;
                                    positiveNo += 1;
                                    if(negativeNo < positiveNo) {
                                        cout << i << endl;
                                        break;
                                    }
                                }
                            
                        }
                    } else {
                        if(negativeNo <= positiveNo)    cout << 1 << "\n";
                        else {
                            if(((negativeNo - positiveNo)/2) % 2 == 0) cout << (negativeNo - positiveNo)/2 + 1 << "\n";
                            else    cout << (negativeNo - positiveNo) << "\n";
                        }
                    }
                }
                 
            }
        }
    }
}