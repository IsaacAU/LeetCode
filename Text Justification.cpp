class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res, line;
        int i=0, num=0;
        bool unfinish=false;
        while(i<words.size()){
            if(words[i].length()>L) return vector<string>();
            int newLen=(num==0?num:num+1)+words[i].length();
            if(newLen<L){
                line.push_back(words[i]);
                num=newLen;
                ++i;
                if(i==words.size()) unfinish=true;
            }else if(newLen==L){
                num=newLen; line.push_back(words[i]);
                string s=format(line, num, L, i==words.size()-1);
                res.push_back(s);
                num=0;  line.clear();
                ++i;
            }else{
                string s=format(line, num, L, false);
                res.push_back(s);
                num=0;  line.clear();
            }
        }
        if(unfinish){
            string s=format(line, num, L, true);
            res.push_back(s);
        }
        return move(res);
    }
private:
    string format(vector<string> &line, int num, int L, bool last){
        string res;
        if(last){
            res=line[0];
            for(int i=1; i<line.size(); ++i)
                res+=" "+line[i];
            res+=string(L-num, ' ');
        }else{
            if(line.size()==1){
                res=line[0]+string(L-num, ' ');
            }else{
                int extra=L-num;
                int each=extra/(line.size()-1)+1;
                int rem=extra%(line.size()-1);
                for(int i=0; i<rem; ++i)    res+=line[i]+string(each+1,' ');
                for(int i=rem; i<line.size()-1; ++i)    res+=line[i]+string(each, ' ');
                res+=line.back();
            }
        }
        return move(res);
    }
};
