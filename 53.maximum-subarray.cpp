/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans=INT_MIN, sum=0;

        for(int i = 0; i< n; i++) {

            sum+=nums[i];
            ans = max(ans, sum);
            if(sum <0) {
                sum = 0;
            }
        }
        return ans;

        
    }
};
// @lc code=end

