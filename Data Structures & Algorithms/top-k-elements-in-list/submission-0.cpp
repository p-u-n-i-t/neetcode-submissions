class Solution {
public:
    vector<int> topKFrequent(vector<int>& input, int k) {
            map<int,int>freq;
            int n=input.size();
            for(int i=0;i<n;i++){
                freq[input[i]]++;
            }
            multiset<pair<int,int>>solution;

            for(auto &it: freq){
                if(solution.size()<k){
                    solution.insert({it.second,it.first});
                }
                else{
                    auto x= *solution.begin();
                    if(x.first<it.second){
                        solution.erase(solution.begin());
                        solution.insert({it.second,it.first});
                    }
                }
            }

            vector<int>only_solution;
            for(auto &it: solution){
                only_solution.push_back(it.second);
            }
            sort(only_solution.rbegin(),only_solution.rend());

            return only_solution;
    }
};
