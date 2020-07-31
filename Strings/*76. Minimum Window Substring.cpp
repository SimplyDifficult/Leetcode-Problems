class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0||t.size()==0)return"";
        vector<int>req(128,0);
        for(int i=0;i<t.size();i++)req[t[i]]++;
        int l=0,r=0,len=INT_MAX,index=0;
        int requ=t.size();
        while(r<=s.size() && l<s.size()){
            if(requ){
                req[s[r]]--;
                if(req[s[r]]>=0)requ--;
                r++;
            }
            else{
                if((r-l)<len){
                    len=r-l;
                    index=l;
                }
                req[s[l]]++;
                if(req[s[l]]>0)requ++;
                l++;
            }
        }
        if(len==INT_MAX)return"";
        return s.substr(index,len);
    }
};
