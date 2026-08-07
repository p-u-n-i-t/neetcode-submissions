class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int>s1_alphabet(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            s1_alphabet[s1[i]-'a']++;

        }

        if(s1.size()>s2.size()) return false;
       vector<int>s2_alphabet(26);
       for(int i=0;i<n;i++){
                s2_alphabet[s2[i]-'a']++;
       }

      
        if(s1_alphabet==s2_alphabet) return true;

       

        int removing_index=0;
       for(int i=n;i<s2.size();i++){
        s2_alphabet[s2[removing_index]-'a']--;
        s2_alphabet[s2[i]-'a']++;
        
        
        if(s1_alphabet==s2_alphabet) return true;
        removing_index++;
       }

        return false;

    }
};
