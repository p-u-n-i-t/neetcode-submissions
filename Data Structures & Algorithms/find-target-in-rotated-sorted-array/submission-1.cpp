class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right =nums.size()-1;

        while(left<right){
            int middle =left+(right-left)/2;
            // cout<<"middle-->"<<middle<<endl;
            // cout<<"middle_number-->"<<nums[middle]<<endl;

            if(nums[middle]>nums[right]){
                if(target<=nums[right]||target>nums[middle]) left=middle+1;
                else right =middle;
            }
            else{
                if(nums[middle]<target&&nums[right]>=target) left=middle+1;
                else right=middle;;
            }
            // cout<<"next_left-->"<<left<<"   next_right"<<right<<endl;
            // cout<<"next_left_number-->"<<nums[left]<<"   next_right_number"<<nums[right]<<endl;
        }

        if(left>=nums.size()||nums[left]!=target) return -1;
        else return left;
    }
};
