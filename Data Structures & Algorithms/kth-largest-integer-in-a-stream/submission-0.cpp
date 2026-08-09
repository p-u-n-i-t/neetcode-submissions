class KthLargest {
    private :
    priority_queue<int,vector<int>,greater<int>>kth_largest_element;
    int limit;
public:
    KthLargest(int k, vector<int>& nums) {
        limit =k;
        for(int i=0;i<nums.size();i++) add(nums[i]);
        

    }
    
    int add(int val) {
      
            kth_largest_element.push(val);
            if(kth_largest_element.size()>limit) kth_largest_element.pop();
            return kth_largest_element.top();
        
    }
};
