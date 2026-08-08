class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right = matrix.size()-1;

        while(left<=right){
            int middle=left+(right-left)/2;
                                          
            if(matrix[middle][0]>target) right=middle-1;
            else if(matrix[middle][matrix[middle].size()-1]<target) left=middle+1;
            else{
                int low=0;
                int high=matrix[middle].size()-1;
               
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(matrix[middle][mid]>target) high=mid-1;
                    else  low=mid+1;
                }
               
                if(matrix[middle][high]==target) return true;
                else return false;
            }
        }
        return false;
    }
};
