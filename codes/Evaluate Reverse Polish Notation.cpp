class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for(auto s: tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                assert(!stk.empty());
                int b=stk.top();    stk.pop();
                assert(!stk.empty());
                int a=stk.top();    stk.pop();
                if(s=="+")
                    stk.push(a+b);
                else if(s=="-")
                    stk.push(a-b);
                else if(s=="*")
                    stk.push(a*b);
                else
                    stk.push(a/b);
            }else
                stk.push(stoi(s));
        }
        assert(stk.size()==1);
        return stk.top();
    }
};
