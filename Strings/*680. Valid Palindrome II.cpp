class Solution {
public:
    
    bool check(string s,int i,int j){
        for(int k=i;k<=(i+j)/2;k++){
            if(s[k]!=s[j-k+i])return false;
        }
        return true;
    }
        
    bool validPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            int j=n-i-1;
            if(s[i]!=s[j]){
                return (check(s,i+1,j)||check(s,i,j-1));
            }
        }
        return true;
    }
};
