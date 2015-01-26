class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=2; i<=n; ++i){
            string next;
            char c=res[0];  int t=1;
            for(int j=1; j<res.length(); ++j){
                if(res[j]==c)    ++t;
                else{
                    next.push_back(t+'0');
                    next.push_back(c);
                    c=res[j];
                    t=1;
                }
            }
            next.push_back(t+'0');
            next.push_back(c);
            res=next;
        }
        return res;
    }
};
