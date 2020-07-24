bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==0)
        {
            //do something
            vector<vector<int> >dp(nums.size(), vector<int>(sum / 2 + 1, -1));

            return dega(dp,nums,n,sum/2);
        }
        else
        {
            return false;
        }
    }
    bool dega(vector<vector<int> >&dp,vector<int>& nums,int n,int w)
    {
        if(w==0) return true;
        if(n==0) return false;
        if(dp[n-1][w]!=-1)
        {
            return dp[n-1][w];
        }
        else
        {
            if(nums[n-1]<=w)
            {
                //do something
                return dp[n-1][w]=dega(dp,nums,n-1,w-nums[n-1])||dega(dp,nums,n-1,w);
            }
            else
            {
                return dp[n-1][w]=dega(dp,nums,n-1,w);
            }
        }
    
    }
