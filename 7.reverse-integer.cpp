/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long int x1=x;
        bool flag=0;
        if(x1<0) flag=1;
        x1=abs(x1);
        long long int ans=0;
        while(x1>0)
        {
            ans=ans*10+x1%10;
            x1/=10;
        }
        if(ans>pow(2,31)) return 0;
        if(flag) ans*=-1;
        return ans;
    }
        
};
// @lc code=end

