class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>set;
        for(int x:nums)set.insert(x);
        int len=0;
        for(int x:nums){
            if(set.find(x-1)==set.end()){
                int currlen=1;
                int currnum=x+1;
                while(set.find(currnum)!=set.end()){
                    currlen++;
                    currnum++;
                }
                len=max(len,currlen);
            }
        }
        return len;
    }
};
