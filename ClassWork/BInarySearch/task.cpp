// There are n task with ith task having A[i] difficulty. Divide the n task among k people . You can only give some consecutive tasks only to any person. Minimize the maximum difficulty given to any individual.

#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> &p) {
    int Sum = 0;
    for(int i=0; i<p.size(); i++)   Sum += p[i];
    return Sum;
}

int max(vector<int> &p) {
    int Max = INT_MIN;
    for(int i=0; i<p.size(); i++) {
        if(Max <= p[i])
            Max = p[i];
    }
    return Max;
}

// Function for checking that can we give task to k person, in mid value

bool check(vector<int> &p, int k, int mid) {
    int t=1;
    int currentSum = 0;
    for(int i=0; i<p.size(); i++) {
        if(p[i] > mid) 
            return false;
        if(currentSum + p[i] <= mid) {
            currentSum += p[i];
        } else {
            t++;
            currentSum = p[i];
        }
    }
    return t<=k;
}

// Function for finding the minimum task time
int minOfMax(vector<int> &p, int k) {
    int ans = -1;
    int low = max(p);
    int high = sum(p);

    while(low <= high) {
        int mid = (low+high)/2;
        if(check(p, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}


// Main function
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> task;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        task.push_back(temp);
        }
    int Ans = minOfMax(task, k);
    cout << Ans;
}