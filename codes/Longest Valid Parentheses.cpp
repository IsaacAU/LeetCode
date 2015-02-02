class Solution {
public:
    // method 1
    int longestValidParentheses(string s) {
        stack<pair<int,int>> stk;
        int res=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='('){
                stk.push(make_pair(1,0));
            }else{
                if(stk.empty() || stk.top().first<0)
                    continue;
                else if(stk.top().first==0)
                    stk.push(make_pair(-1,0));
                else{
                    --stk.top().first;   ++stk.top().second;
                    if(stk.top().first==0 && stk.size()>1){
                        pair<int,int> p=stk.top();  stk.pop();
                        if(stk.top().first<0)   stk.push(p);
                        else    stk.top().second+=p.second;
                    }
                    res=max(res, 2*stk.top().second);
                }
            }
        }
        return res;
    }
    
    // method 2
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='(')
                stk.push(i);
            else if(!stk.empty() && s[stk.top()]=='('){
                stk.pop();
                int start=stk.empty()?-1:stk.top();
                res=max(res, i-start);
            }else
                stk.push(i);
        }
        return res;
    }
};
