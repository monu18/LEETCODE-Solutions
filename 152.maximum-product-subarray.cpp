/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int minP = nums[0];
        int maxP = nums[0];

        for(int i =1; i< n; i++) {
            if(nums[i]<0) {
                swap(minP, maxP);
            }
            minP = min(nums[i], minP * nums[i]);
            maxP = max(nums[i],  maxP * nums[i]);
            ans = max(ans, max(maxP, minP));
        }
        return ans;
        
    }
};
// @lc code=end

