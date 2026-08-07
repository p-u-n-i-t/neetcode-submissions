class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char>paranthesis;
        paranthesis.push(s[0]);

        for(int i=1 ;i<s.size();i++){
            if(paranthesis.empty()){
                paranthesis.push(s[i]);
                continue;
            }
            char p=paranthesis.top();
            if(s[i]==')'&&p=='(') {
                paranthesis.pop();
                continue;
            }
            else if(s[i]=='}'&&p=='{'){
                 paranthesis.pop();
                continue;
            }
            else if(s[i]==']'&&p=='[')
            {
                 paranthesis.pop();
                continue;
            }
            paranthesis.push(s[i]);

        }

        if(paranthesis.size()==0) return true;
         return false;
    }
};
