class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stack;
        int ans=0;
        stack.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                stack.push(i);
            else{
                stack.pop();
                if(stack.empty())stack.push(i);
                ans=max(ans,i-stack.top());
            }
        }
        return ans;
    }
};

/*For every ‘(’ encountered, we push its index onto the stack.
For every ‘)’ encountered, we pop the topmost element and subtract
the current element's index from the top element of the stack, which gives the 
length of the currently encountered valid string of parentheses. If while popping 
the element, the stack becomes empty, we push the current element's index onto the stack.*/
