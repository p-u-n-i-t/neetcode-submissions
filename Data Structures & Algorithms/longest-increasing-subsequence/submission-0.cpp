class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
       
       vector<int>dp(n);
       dp[0]=1;

       for(int i=1;i<n;i++){
            int j=i-1;
            int max_freq=0;
            while(j>=0){
                if(nums[j]<nums[i]) max_freq=max(max_freq,dp[j]);
                j--;
            }
            dp[i]=max_freq+1;
          

       }

       int x=*max_element(dp.begin(),dp.end());
       return x;

       
    }
};