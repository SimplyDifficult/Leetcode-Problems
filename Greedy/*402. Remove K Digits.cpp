class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>stack;
        int n=num.size();
        int keep=n-k;
        for(int i=0;i<n;i++){
            while(!stack.empty() && stack.top()>num[i] && k>0){
                stack.pop();
                k--;
            }
            stack.push(num[i]);
        }
        string ans;
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        ans.resize(keep);
        while(!ans.empty() && ans[0]=='0')ans.erase(ans.begin());
        if(ans.empty())return "0";
        return ans;
    }
};
