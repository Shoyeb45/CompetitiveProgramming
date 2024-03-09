#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &v, int x) {
    int lower = 0;
    int upper = v.size() - 1;
        int LB = v.size();
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(v[mid] < x) {
                lower = mid + 1;
            } else{
                LB = mid;
                upper = mid - 1;
            } 
        }
        return LB;
}
int upperBound(vector<int> &v, int x) {
    int lower = 0;
    int upper = v.size() - 1;
    int UB = 0;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(v[mid] > x) {
                upper = mid - 1;
            } else {
                UB = mid+1;
                lower = mid + 1;    
            }
        }
        return UB;
}
bool isPresent(vector<int> &v, int x) {
    int upper = v.size() - 1;
    int lower = 0;

    while (lower <= upper) {
        int mid = (upper + lower)/ 2;
        if(v[mid] == x)    return true;
        else if(v[mid] < x)   lower = mid +1;
        else    upper = mid - 1;
    }
    return false;
    }

        
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)  cin >> a[i];
    int x;
    cin >> x;
    cout << isPresent(a, x) << '\n';
    cout << lowerBound(a, x) << " " << upperBound(a, x);

}

