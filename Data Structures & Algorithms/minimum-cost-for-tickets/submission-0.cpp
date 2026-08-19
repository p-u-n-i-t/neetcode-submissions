class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366);
        
       int index=1;
        int n=days.size();
       
       for(int i=0;i<n;i++){
            if(i!=0) index=days[i-1]+1;
            while(index<days[i]){
                dp[index]=dp[index-1];
                 index++;   
            }
            int x,y;
            if(days[i]<7) x=0;
            else x=dp[days[i]-7];
            if(days[i]<30) y=0;
            else y=dp[days[i]-30];

            dp[days[i]]=min(min(dp[days[i]-1]+costs[0],x+costs[1]),y+costs[2]);
           

       }

       return dp[days[n-1]];
    }
};