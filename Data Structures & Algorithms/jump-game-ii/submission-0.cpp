class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size());
        int jump_number=0;
        int jump_power=nums[0];

        int index=1;
        while(index<nums.size()){
            int next_jump_power=0;
            while(index<nums.size()&&jump_power--){
                
                next_jump_power=max(next_jump_power,nums[index]);
                index++;
            }
            jump_number++;
            jump_power=next_jump_power;
        }

        return jump_number;
    }
};
