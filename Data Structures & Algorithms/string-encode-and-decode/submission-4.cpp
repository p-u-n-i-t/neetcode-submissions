class Solution {
     private: vector<int>string_size;
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        int n =strs.size();
        for(int i=0;i<n;i++){
            encoded_string+=strs[i];
            string_size.push_back(strs[i].size());
            
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
            int n=s.size();
            int index=0;
            vector<string>star(string_size.size());
             for(int i=0;i<string_size.size();i++){
                for(int j=0;j<string_size[i];j++){
                    star[i]+=s[index];
                    index++;
                }
             }
           
            return star;
    }   
};
