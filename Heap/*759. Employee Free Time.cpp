/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        int n=schedule.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<schedule[i].size();j++){
                min_heap.push({schedule[i][j].start,schedule[i][j].end});
            }
        }
        vector<Interval>ans;
        int currs=min_heap.top().first;
        int curre=min_heap.top().second;
        min_heap.pop();
        while(!min_heap.empty()){
            int s=min_heap.top().first;
            int e=min_heap.top().second;
            if(s>curre){
                ans.push_back({curre,s});
                currs=s;
                curre=e;
            }
            else{
                curre=max(curre,e);
            }
            min_heap.pop();
        }
        return ans;
    }
};
