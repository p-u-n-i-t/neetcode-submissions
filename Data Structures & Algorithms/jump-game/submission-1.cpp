class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int current_remaining_blocks=0;
        
        for(int i=0;i<nums.size();i++){
            current_remaining_blocks--;
            if(nums[i]!=0)  current_remaining_blocks=max(current_remaining_blocks,nums[i]);
            if(i!=nums.size()-1&&current_remaining_blocks<=0) return false;
        }

        return true;

    }
};
