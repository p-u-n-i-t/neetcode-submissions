class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hours_consumed=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0)   hours_consumed+=piles[i]/mid;
                else hours_consumed+=piles[i]/mid+1;

            }
           
            if(hours_consumed<=h) high=mid-1;
            else low=mid+1;
        }

        return low;
    }
};
