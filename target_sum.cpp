#include<bits/stdc++.h>
using namespace std;
int util(vector<int>&v, int sum,int n, int target_sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=0;
    }for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(v[i-1]==0)
            {
              dp[i][j]=dp[i-1][j];
            }
            else if(v[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target_sum];
}
int findTargetSumWays(vector<int>& v, int S) {
        int diff=S;
        int sum=0;
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(v[i]==0) count++;
        }
        if(sum<diff) return 0;
        if((diff+sum)%2==1) return 0;
       // vector<vector<int> >dp(n+1,vector<int>(sum+1));
        int target_sum=(diff+sum)/2;
        // cout<<"target_sum "<<target_sum<<"\n";
        // cout<<"sum-target_sum "<<sum-target_sum<<"\n";
        return pow(2,count)*util(v,sum,n,target_sum);

    }


int main(){
  int n,diff;
  cin>>n>>diff;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  cout<<findTargetSumWays(v,diff);

  return 0;
}
