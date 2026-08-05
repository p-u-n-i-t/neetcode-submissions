class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total_product=1;
        int total_number_of_zero=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0)total_product*=nums[i];
            else total_number_of_zero++;
        }

        vector<int>product_without_self(n);
        if(total_number_of_zero>1) return product_without_self;
        for(int i=0;i<n;i++){
            if(total_number_of_zero==1){
                if(nums[i]==0) product_without_self[i]=total_product;
                else product_without_self[i]=0;
            }
            else
            product_without_self[i]=total_product/nums[i]  ;
         }

         return product_without_self;
    }
};
