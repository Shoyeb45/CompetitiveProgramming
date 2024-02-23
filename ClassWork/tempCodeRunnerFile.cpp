 int search(vector<int>& nums, int target) {
         int minInd = nums.size();
        int lower = 0;
        int upper = nums.size()-1;
        
        while(lower <= upper) {
            int mid = (lower + upper)/2;
            if(mid < nums.size()-1 && nums[mid] > nums[mid+1]) {
                minInd = mid+1;
                break;
            } else if(nums[0] > nums[mid]) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        } 

        if(nums[0] >= target) {
            lower = minInd;
            upper = nums.size() - 1;
        } else {
            lower = 0;
            upper = minInd - 1;
        }
        int ans = -1;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            } else if(nums[mid] > target) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return ans;
    }