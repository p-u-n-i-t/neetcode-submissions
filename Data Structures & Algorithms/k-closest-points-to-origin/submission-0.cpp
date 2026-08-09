class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>min_distance;

        for(int i=0;i<points.size();i++){
            int distance_square=0;
            for(int j=0;j<points[i].size();j++){
                     distance_square+=(points[i][j])*(points[i][j]);
            }
       
     min_distance.push({distance_square,{points[i][0],points[i][1]}});
            
            if(min_distance.size()>k){
               
                min_distance.pop();
            } 
        }

        vector<vector<int>>return_cordinates(min_distance.size());
        int n=min_distance.size();
        for(int i=0;i<n;i++){
            auto x=min_distance.top();
            return_cordinates[i].push_back(x.second.first);
             return_cordinates[i].push_back(x.second.second);
            min_distance.pop();
        }

        return return_cordinates;
    }
};
