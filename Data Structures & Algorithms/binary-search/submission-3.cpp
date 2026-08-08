class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right =nums.size()-1;

        while(left<=right){
            int middle =left+(right -left)/2;

            if(nums[middle]>target) right=middle-1;
            else left=middle+1;
        }

        if(right<0||nums[right]!=target) return -1;
        else return right;

    }
};
