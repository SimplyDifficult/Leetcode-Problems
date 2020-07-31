class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)return true;
        if(s.size()==1)return false;
        stack<char>stack;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(stack.size()==0)return false;
                if(s[i]==')'&&stack.top()!='(')return false;
                if(s[i]=='}'&&stack.top()!='{')return false;
                if(s[i]==']'&&stack.top()!='[')return false;
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
        }
        if(stack.size()==0)return true;
        return false;
    }
};
