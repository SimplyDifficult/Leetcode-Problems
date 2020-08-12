class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>mp;
        int n=stones.size();
        
        for(int i=0;i<n;i++){
            mp[stones[i]]=unordered_set<int>{};
        }
        mp[stones[0]].insert(1);
        
        int target=stones[n-1];
        
        for(int i=0;i<stones.size()-1;i++){
            int stone=stones[i];
            for(int step:mp[stone]){
                int reach=stone+step;
                if(reach==target)return true;
                if(mp.count(reach)){
                    mp[reach].insert(step);
                    mp[reach].insert(step+1);
                    if(step>1)mp[reach].insert(step-1);
                }
            }
        }
        return false;
    }
};
