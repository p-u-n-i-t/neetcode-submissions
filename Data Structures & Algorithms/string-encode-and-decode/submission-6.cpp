class Solution {
   
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        int n =strs.size();
        encoded_string+=to_string(n)+'#';
        for(int i=0;i<n;i++){
            encoded_string+=to_string(strs[i].size())+'#';
            encoded_string+=strs[i];
           
            
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
             int i=0;
             string size_star;
             int i_size=0;
             while(s[i_size]!='#'){
                size_star+=s[i_size];
                i_size++;
             }
             i=i_size+1;
             
             
            vector<string>star(stoi(size_star));
           
            int index=0;
    
            while(i<s.size()){
                string s_i_size;
                 while(s[i]!='#'){
                s_i_size+=s[i];
                i++;
             }
                for(int j=i+1;j<i+1+stoi(s_i_size);j++){
                    star[index]+=s[j];
                }
                index++;
                i=i+1+stoi(s_i_size);
            }
           
            return star;
    }   
};
