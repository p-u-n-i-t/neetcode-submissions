class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        if(s.empty()) return 0;

        map<char,int>char_position;
      

        int current_length=0;
        int max_length=1;

        int string_starting_index=0;

        for(int i=0;i<n;i++){
            if(char_position[s[i]]!=0){
                if(string_starting_index>char_position[s[i]]){
                    current_length++;
                    char_position[s[i]]=i+1;
                     continue;}
                string_starting_index=char_position[s[i]];
                max_length=max(current_length,max_length);
                 current_length=(i+1)-char_position[s[i]];
                char_position[s[i]]=i+1;
               
            }
            else{
                char_position[s[i]]=i+1;
                current_length++;
            }
            // cout<<i<<"::"<<s[i]<<"->"<<char_position[s[i]]<<":::index->"<<string_starting_index<<endl;
            // cout<<current_length<<endl;
            // cout<<max_length<<endl;
        }
        max_length=max(current_length,max_length);
       


        return max_length;

    }
};
