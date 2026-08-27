class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(s.size());
        if(s[0]=='0') return 0;
        dp[0]=1;

        for(int i=1;i<n;i++){
              string temp = s.substr(i - 1, 2);
              int x= stoi(temp);
                if(x==0) return 0;
                if(s[i]!='0') dp[i]=dp[i-1];
                
                if(i==1&&x<=26) dp[i]++;
                else if(x<=26&&x>=10) dp[i]+=dp[i-2];
                
        }
       

        return dp[n-1];

    }
};
