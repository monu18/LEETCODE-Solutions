/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int leftMax(vector<int>& prices, int start) {
        int left, right , ans =0;
        left =0, right =0;
            while(right<start) {
                if(prices[right] > prices[left]) {
                    ans=max(ans, prices[right] - prices[left]);
                }
                else{
                    left=right;
                }
                right++;
            }

        return ans;
    }
    int rightMax(vector<int>& prices, int end) {
        int left, right , ans =0;
            left = end;
            right=end;
            while(right<prices.size()) {
                if(prices[right] > prices[left]) {
                    ans=max(ans, prices[right] - prices[left]);
                }
                else{
                    left=right;
                }
                right++;
            }

        return ans;
    }
    int maxLoss(vector<int>& prices, int start, int end) {
        int left=end, right=end , ans =0;
        while (right>start)
        {
            if(prices[left] > prices[right]) {
                ans = max(ans, prices[left] - prices[right]);
            }
            else{
                right = left;
            }
            left--;
        }
        return ans;
        
    }
    int maxProfit(vector<int>& prices) {
        
        int max_profit=0, left_profit=0, right_profit=0, loss = 0, left=0, right=1, begin =0, end=0;
        int n=prices.size();
        // find max profit range
        // then find 2nd max profit in range before, after and in max range

        int left_index=0, right_index=1;
        while(right<n) {
            if(prices[right] > prices[left]) {
                if(max_profit<(prices[right] - prices[left])) {
                    max_profit = prices[right] - prices[left];
                    left_index = left;
                    right_index = right;
                }
                
            }
            else{
                left=right;
            }
            right++;

        }
        // cout<<"left_index "<<left_index<<"\n";
        // cout<<"right_index "<<right_index<<"\n";
        int left_max = leftMax(prices, left_index);
        int right_max = rightMax(prices, right_index+1);
        int max_loss = maxLoss(prices, left_index+1, right_index-1);

        // cout<<"max_profit"<<max_profit<<"\n";
        // cout<<"left_max"<<left_max<<"\n";
        // cout<<"right_max"<<right_max<<"\n";
        // cout<<"max_loss"<<max_loss<<"\n";


        return max_profit + max(left_max, max(right_max, max_loss));




        // if(ans1==0) return 0;

        // if(left_index==0 && right_index==1) {
        //     left = 2, right = 2;
        // }
        // else if(left_index ==0 && right_index!=1) {
        //     left = 1, right = 1;
        // }
        // else {
        //     left = right = 0;
        // }

        // while(right<n) {
        //     if(right==left_index || right == right_index) {
        //         continue;
        //     }
        //     if(prices[right] > prices[left]) {
        //         if(ans2<(prices[right] - prices[left])) {
        //             ans2 = prices[right] - prices[left];
        //             left_index = left;
        //             right_index = right;
        //         }

        //     }
        //     else{
        //         left=right;
        //     }
        //     right++;
        // }
        // return ans1 + ans2;


        // int ans=0, mx=0, left=0, right=1;

        // int n = prices.size();
        // vector<int> v;
        // while(right<n) {
        //     if(prices[right] > prices[right-1]) {
        //         mx=prices[right] - prices[left];
        //     }
        //     else {
        //         v.push_back(mx);

        //         left=right;
        //         mx=0;
        //     }
        //     right++;
        // }
        // v.push_back(mx);
        // sort(v.begin(), v.end(), greater<int>());
        // int counter=0;
        // for(auto x:v) {
        //     // cout<<"x= "<<x<<"\n";
        //     if(counter<2) {
        //         ans+=x;
        //     }
        //     else{
        //         break;
        //     }
        //     counter++;
        // }
        // return ans;
        
    }
};
// @lc code=end

