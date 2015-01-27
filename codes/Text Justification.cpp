class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        if(words.empty())   return res;
        int i=0, cur=0;
        vector<string> line;
        while(i<words.size()){
            if(cur+line.size()+words[i].length()==L){
                line.push_back(words[i]);
                res.push_back(string());
                for(auto s:line){
                    if(res.back().empty())
                        res.back()+=s;
                    else
                        res.back()+=" "+s;
                }
                line.clear();
                cur=0;
                ++i;
            }else if(cur+line.size()+words[i].length()>L){
                res.push_back(string());
                if(line.size()==1){
                    res.back()+=line[0];
                    res.back()+=string(L-cur, ' ');
                }else{
                    int each=(L-cur)/(line.size()-1);
                    int rem=(L-cur)%(line.size()-1);
                    int i=0;
                    for(; i<line.size()-1; ++i){
                        res.back()+=line[i];
                        res.back()+=string(each, ' ');
                        if(i<rem)   res.back()+=" ";
                    }
                    res.back()+=line[i];
                }
                cur=0;
                line.clear();
            }else{
                line.push_back(words[i]);
                cur+=words[i].length();
                ++i;
            }
        }
        if(!line.empty()){
            res.push_back(string());
            if(line.size()==1){
                res.back()+=line[0];
                res.back()+=string(L-cur, ' ');
            }else{
                for(auto s:line){
                    if(res.back().empty())
                        res.back()+=s;
                    else
                        res.back()+=" "+s;
                }
                res.back()+=string(L-cur-line.size()+1, ' ');
            }
        }
        if(res.empty() && L>0)
            res.push_back(string(L, ' '));
        return res;
    }
};
