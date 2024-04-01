#include<bits/stdc++.h>
using namespace std;

int minInd(vector<int>& nums) {
           int ind = -1;
           int low = 0;
           int high = nums.size() - 1;

           while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] <= nums[mid+1] && nums[mid] < nums[mid-1] && (mid >= 1 && mid <= nums.size() - 1)) {
                ind = mid;
                high = mid - 1;
            } else if(nums[mid] <= nums[0]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
           }

        //    if((ind <= nums.size() - 2 )&& (ind >= 1)) return ind;

        //    if(nums[0] >= nums[1])   return 0;

        //    return nums.size() - 1;
        return ind;
}



 bool search(vector<int>& nums, int target) {
        int ind = minInd(nums);
        int low = 0, high = nums.size() - 1;
        if(target <= nums[0] ) {
            low = ind;
            high = nums.size() - 1;
        } else if(target > nums[0]) {
            low = 0;
            high = ind - 1;
        }

        while (low <= high) {
            int mid = (high + low)/2;

            if(nums[mid] == target) return true;
            else if (nums[mid] > target)    high = mid - 1;
            else    low = mid + 1;
        }
        return false;
}


int main() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << minInd(a) << endl;

    cout << search(a, t) << endl;\
        
}