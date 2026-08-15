class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>sub_string;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int x=nums[i];
            if(sub_string.empty()||sub_string.back()<x) sub_string.push_back(x);
            else{
                auto it=lower_bound(sub_string.begin(),sub_string.end(),x);
                *it=x;
            }
        }

        return sub_string.size();
    }
};
