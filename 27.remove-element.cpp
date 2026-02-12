/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for(int num : nums) {
            if(num!=val) {
                nums[ans] = num;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

