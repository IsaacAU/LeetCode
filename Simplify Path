class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string cur;
        bool root=path[0]=='/';
        for(int i=0; i<=path.length(); ++i){
            if(i==path.length() || path[i]=='/'){
                if(cur.empty())
                    continue;
                if(cur=="."){
                    cur.clear();
                    continue;
                }
                if(cur==".."){
                    if(!stk.empty())
                        stk.pop();
                }else{
                    stk.push(cur);
                }
                cur.clear();
            }else
                cur+=path[i];
        }
        string res;
        if(!stk.empty()){
            res=stk.top();  stk.pop();
        }
        while(!stk.empty()){
            res=stk.top()+'/'+res;
            stk.pop();
        }
        if(root)    res="/"+res;
        return res;
    }
};
