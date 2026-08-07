class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>max_elements;
        int n=nums.size();

        for(int i=0;i<k;i++){
            max_elements.insert(nums[i]);
        }
        vector<int>max_element_in_window;
        int last_element=*max_elements.rbegin();
        max_element_in_window.push_back(last_element);

        int removing_element_index=0;
        for(int i=k;i<n;i++){
            max_elements.erase(max_elements.find(nums[removing_element_index]));
            removing_element_index++;
            max_elements.insert(nums[i]);

             last_element=*max_elements.rbegin();
        max_element_in_window.push_back(last_element);
        }

        return max_element_in_window;
    }
};
