class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
    
        vector<int>right_maximum(n);
        vector<int>left_maximum(n);
        right_maximum[n-1]=0;
        left_maximum[0]=0;

        for(int i=1;i<n;i++){
            left_maximum[i]=max(height[i-1],left_maximum[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right_maximum[i]=max(height[i+1],right_maximum[i+1]);
        }

        int total_water=0;
        for(int i=0;i<n;i++){
            int height_of_tower=min(left_maximum[i],right_maximum[i]);
            
            int water_stored=(height_of_tower-height[i]);
            if(water_stored<0) continue;
            total_water+=water_stored;
        }

        return total_water;

    }
};
