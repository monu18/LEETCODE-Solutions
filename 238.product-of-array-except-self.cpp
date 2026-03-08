/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<pair<int, int>>v;
        // for(int i = 0; i< n; i++) {
        //     if(i==0) {
        //         v.push_back(make_pair(1,0));
        //     }
        //     else {
        //         v.push_back(make_pair(v[i-1].first*nums[i-1],0));
        //     }
        // }

        // for(int i = n-1; i>=0; i--) {
        //     if(i==n-1) {
        //         v[i].second = 1;
        //     }
        //     else {
        //         v[i].second = v[i+1].second * nums[i+1];
        //     }
        // }
        // for(int i =0; i< n; i++) {
        //     nums[i] = v[i].first * v[i].second;
        // }
        // return nums;
        int n = nums.size();
        vector<int> res(n);

        res[0] = 1;
        for(int i = 1; i < n; i++)
            res[i] = res[i-1] * nums[i-1];

        int right = 1;
        for(int i = n-1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
        
    }
};
// @lc code=end

