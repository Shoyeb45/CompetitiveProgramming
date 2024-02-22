// given two string one is original and one is subsequence , and one array where you have position of elements, return the minimum number of the characters you can delete from the original string according to order of the permutation, such that subsequence is not preserved.


#include<bits/stdc++.h>
using namespace std;

bool isSubsequ(string o, string ss) {
    int i=0, j=0;

    while(i < o.size() && j < ss.size()) {
        if(o[i] == ss[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if(j == ss.size()) {
        return true;
    } 

    return false;
}

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> p;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }
    int n = s.size();
    int low = 0;
    int high = n;

    while (low <= high)
    {
        if(isSubsequ(s, t));
    }
    


}