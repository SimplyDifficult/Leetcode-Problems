class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>dict={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.empty())return ans;
        ans.push_back("");
        
        for(int i=0;i<digits.size();i++){
            while(ans.front().size()==i){
                string temp=ans.front();
                ans.erase(ans.begin());
                for(char c:dict[digits[i]-'0'])
                    ans.push_back(temp+c);
            }
        }
        return ans;
    }
};
