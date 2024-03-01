#include<bits/stdc++.h>
using namespace std;

// function for checking that the subaarray is still sub array or not after removing the mid elements
bool isSubs(string orgStr, string subStr, vector<int> &index, int mid) {
    string oS = orgStr;
    for(int i=0; i<mid; i++)    oS[index[i]] = '#';

    int i = 0, j = 0;
    while (i < oS.size() && j < subStr.size()) {
        if(oS[i] == subStr[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    if(j == subStr.size()) {
        return true;
    }

    return false;
}

int finalAns(string orgStr, string subStr, vector<int> &index) {
    int n = orgStr.size();
    int low = 0;
    int high = n;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high)/2;

        if(isSubs(orgStr, subStr, index, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    string orgStr, subStr;
    cin >> orgStr >> subStr;
    int n;
    cin >> n;
    vector<int> index(n);
    for(int i=0; i<n; i++)  cin >> index[i];

    cout << finalAns(orgStr, subStr, index)+1;
}