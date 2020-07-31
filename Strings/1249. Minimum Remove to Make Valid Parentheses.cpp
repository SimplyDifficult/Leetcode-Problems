class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>se;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                if(st.empty())se.insert(i);
                else st.pop();
            }
        }
        while(!st.empty()){
            se.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(se.find(i)==se.end())
                ans.push_back(s[i]);
        }
        return ans;
    }
};
