#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int ind = minInd(nums);
        if (nums[ind] == target)
            return 1;
        auto it = nums.begin();
        if (target >= nums[0] || ind == nums.size() - 1)
            return binary_search(it, it + ind + 1, target);
        else
            return binary_search(it + ind + 1, it + nums.size(), target);
    }

    int minInd(vector<int>& nums) {

        int low = 0;
        int high = nums.size();
        int mid;
        if (nums.size() == 1)
            return 0;
        if (nums.size() == 2)
            return (nums[0] < nums[1]) ? 1 : 0;

        while (low < high) {
            while (low < high - 1 && nums[low] == nums[low + 1])
                low++;
            int mid = (low + high) / 2;
            if (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] > nums[low])
                low = mid;
            else
                high = mid;
        }

        return mid;
    }
};