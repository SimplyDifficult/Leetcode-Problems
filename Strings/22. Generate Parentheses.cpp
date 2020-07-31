class Solution {
public:
    
    vector<string>ans;
    
    void f(string curr, int r,int l,int max){
        if(curr.size()==2*max){
            ans.push_back(curr);
            return;
        }
        if(r<max){
            f(curr+'(',r+1,l,max);
        }
        if(l<r){
            f(curr+')',r,l+1,max);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        f("",0,0,n);
        return ans;
    }
};
