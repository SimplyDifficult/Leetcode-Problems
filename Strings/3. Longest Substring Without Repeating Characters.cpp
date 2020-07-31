class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int n=s.size();
        unordered_set<char>mp;
        int ans=0,i=0,j=0;
        while(i<n && j<n){
            if(mp.find(s[j])==mp.end()){
                mp.insert(s[j]);
                j++;
                ans=max(ans,j-i);
            }
            else{
                mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
