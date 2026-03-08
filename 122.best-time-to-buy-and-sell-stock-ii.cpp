/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, mx=0, left=0, right=1;

        while(right<prices.size()) {
            if(prices[right] > prices[left]) {
                ans += (prices[right] - prices[left]);
            }
            left++;
            right++;
        }

        // while(right<n) {
        //     if(prices[right] > prices[left]) {
        //         mx= max(mx, prices[right] - prices[left]);
        //     }
        //     else {
        //         s.insert(mx);
        //         mx=0;
        //         left=right;
        //     }
        //     right++;
        // }
        return ans;
        
    }
};
// @lc code=end

