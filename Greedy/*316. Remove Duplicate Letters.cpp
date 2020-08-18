class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.size();
        int cnt[26];
        for(int i=0;i<26;i++)cnt[i]=0;
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        int vis[26];
        for(int i=0;i<26;i++)vis[i]=0;
        stack<char>stack;
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']--;
            if(vis[s[i]-'a'])continue;
            while(!stack.empty() && stack.top()>s[i] && cnt[stack.top()-'a']>0){
                vis[stack.top()-'a']=0;
                stack.pop();
            }
            stack.push(s[i]);
            vis[s[i]-'a']=1;
        }
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
