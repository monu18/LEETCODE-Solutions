/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;

        for(int x: nums) {
            s.insert(x);
        }

        return nums.size()!=s.size();
    }
};
// @lc code=end

