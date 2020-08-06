class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans=0;
        stack<int>stack;
        stack.push(INT_MAX);
        for(int a:arr){
            while(stack.top()<=a){
                int temp=stack.top();
                stack.pop();
                ans+=temp*min(a,stack.top());
            }
            stack.push(a);
        }
        while(stack.top()!=INT_MAX){
            int temp=stack.top();
            stack.pop();
            if(stack.top()!=INT_MAX){
                ans+=temp*stack.top();   
            }
        }
        return ans;
    }
};
