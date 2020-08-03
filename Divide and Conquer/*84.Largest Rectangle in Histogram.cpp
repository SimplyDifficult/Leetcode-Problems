class Solution {
public:
    
    int f(vector<int>& heights,int start,int end){
        if(start>end)return 0;
        int minindex=start;
        for(int i=start;i<=end;i++){
            if(heights[i]<heights[minindex])minindex=i;
        }
        int ans=max(heights[minindex]*(end-start+1),max(f(heights,start,minindex-1),f(heights,minindex+1,end)));
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        return f(heights,0,heights.size()-1);
    }
};
