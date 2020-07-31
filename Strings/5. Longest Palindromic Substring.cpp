class Solution {
public:
    
    int maxlen=0,start;
    
    void expand(string s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        if(maxlen<j-i-1){
            maxlen=j-i-1;
            start=i+1;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        for(int i=0;i<s.size();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return s.substr(start,maxlen);
    }
};
