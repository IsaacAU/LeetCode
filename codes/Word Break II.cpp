class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if(s.empty())   return res;
        unordered_map<int, vector<int>> m;
        const int len=s.length();
        for(int i=len-1; i>=0; --i){
            for(int j=i; j<len; ++j){
                string sub=s.substr(i,j-i+1);
                if(dict.count(sub) && (j==len-1 || m.count(j+1)))
                    m[i].push_back(j+1);
            }
        }
        if(m.count(0)){
            vector<string> path;
            search(s, 0, m, res, path);
        }
        return res;
    }
private:
    void search(string &s, int i, unordered_map<int, vector<int>> &m, vector<string> &res, vector<string> &path){
        if(i==s.length()){
            res.push_back(string());
            for(auto s:path){
                if(res.back().empty())
                    res.back()+=s;
                else
                    res.back()+=" "+s;
            }
            return;
        }
        for(auto j:m[i]){
            path.push_back(s.substr(i,j-i));
            search(s, j, m, res, path);
            path.pop_back();
        }
    }
};
