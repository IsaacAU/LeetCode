class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())    return string();
        string res;
        int i=0;
        bool finish=false;
        char c;
        while(1){
            c='\0';
            for(auto s:strs){
                if(i>=s.length()){
                    finish=true;
                    break;
                }
                if(!c)
                    c=s[i];
                else if(c!=s[i]){
                    finish=true;
                    break;
                }
            }
            if(finish)
                break;
            else
                res.push_back(c);
            ++i;
        }
        return move(res);
    }
};
