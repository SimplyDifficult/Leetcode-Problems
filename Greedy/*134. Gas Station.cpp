class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,subsum=INT_MAX,idx;
        int n=gas.size();
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<subsum){
                subsum=total;
                idx=i+1;
            }
        }
        if(total<0)return -1;
        return idx%n;
    }
};
