class Solution {
public:
    int dfs(int ind,vector<int>& nums,int sum,int target,unordered_map<int,unordered_map<int,int>>& dp){
        int n=nums.size();
        if(ind==n){
            return sum==target;
        }

        if(dp[ind].find(sum)!=dp[ind].end()) return dp[ind][sum];
        int ret=0;
        ret+=dfs(ind+1,nums,sum+nums[ind],target,dp);
        ret+=dfs(ind+1,nums,sum-nums[ind],target,dp);
        return dp[ind][sum]=ret;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> dp;
        return dfs(0,nums,0,target,dp);
    }
};
