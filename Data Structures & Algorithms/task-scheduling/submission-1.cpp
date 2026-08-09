class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>total_alphabet(26);
        
        for(int i=0;i<tasks.size();i++){
            total_alphabet[tasks[i]-'A']++;

        }
int max_times=*max_element(total_alphabet.begin(),total_alphabet.end());

            int total_max_elements=0;

            for(int i=0;i<total_alphabet.size();i++){
                if(total_alphabet[i]==max_times) total_max_elements++;
            }
    

     int answer= max((int)tasks.size(),((max_times-1)*n)+(total_max_elements-1)+max_times);
     return answer;
    }
};
