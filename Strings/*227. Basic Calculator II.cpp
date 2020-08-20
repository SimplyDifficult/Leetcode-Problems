class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<long long>stack;
        char sign='+';
        long long ans=0,temp=0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                temp=10*temp+s[i]-'0';
            }
            if(!isdigit(s[i]) && !isspace(s[i]) || i==n-1){
                if(sign=='+')stack.push(temp);
                else if(sign=='-')stack.push(-temp);
                else{
                    int num;
                    if(sign=='*')num=stack.top()*temp;
                    else num=stack.top()/temp;
                    stack.pop();
                    stack.push(num);
                }
                sign=s[i];
                temp=0;
            }
        }
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        return ans;
    }
};
