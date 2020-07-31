class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int>ans;
        int p1=num1.size()-1;
        int p2=num2.size()-1;
        int carry=0;
        while(p1>=0 || p2>=0){
            int x,y;
            if(p1>=0){
                x=num1[p1]-'0';
            }
            else x=0;
            if(p2>=0){
                y=num2[p2]-'0';
            }
            else y=0;
            int val=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            ans.push_back(val);
            p1--;
            p2--;
        }
        if(carry!=0)ans.push_back(carry);
        string s;
        for(int i=ans.size()-1;i>=0;i--){
            s.push_back(ans[i]+'0');
        }
        return s;
    }
};
