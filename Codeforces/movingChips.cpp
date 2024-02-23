#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &v, int ind1, int ind2) {
    int temp = v[ind1];
    v[ind1] = v[ind2];
    v[ind2] = temp;
}

bool isContig (vector<int> &v ) {
    int oneInd = 0;
    int zeroInd = 0;

    for(int i = 0; i<v.size(); i++) {
        if(v[i] == 1) {
            oneInd = i;
            break;
        }
    }

    for(int i=oneInd+1; i<v.size(); i++) {
        if(v[i] == 0) {
            zeroInd = i;
            break;
        }
    }

    for(int i=zeroInd+1; i<v.size(); i++) {
        if(v[i] == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;   
        vector<int> v;

        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        int numOne = 0;
        for(int i=0; i<n; i++) {
            if(v[i] == 1)   numOne++;
        }

        if(numOne == 1 || numOne == n) cout << 0 << '\n';
        else {

            int cnt = 0;
            if(isContig(v))  {
                cout << 0 << '\n';
                }
            else {
            for(int i = n - 1; i >= 0 ; i--) {
                int ind = 0;
                if(v[i] == 1) {
                    for(int j=i-1; j>=0; j--) {
                        if(v[j] == 0) {
                            ind = j;
                            break;
                        }
                    }
                } else {
                    continue;
                }
                
                swap(v, i, ind);
                cnt++;
                if(isContig(v)) break;
            }
            cout << cnt << '\n';
            }

        } 

        for(int i=0; i<n; i++) cout << v[i] << " ";
    }
    
    return 0;
}