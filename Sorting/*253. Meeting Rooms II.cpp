class Solution {
public:
    
   
    static bool compare(vector<int>a,vector<int>b){
        return a[0]<b[0];
    };
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        priority_queue<int,vector<int>,greater<int>>min_heap;
        for(auto i:intervals){
            if(!(min_heap.empty()) && min_heap.top()<=i[0])min_heap.pop();
            min_heap.push(i[1]);
        }
        return min_heap.size();
    }
};
