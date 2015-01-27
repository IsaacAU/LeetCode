class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        if(start==end){
            res.push_back(vector<string>{start});
            return res;
        }
        unordered_set<string> cur, next;
        map<string, vector<string>> prev;
        cur.insert(start);
        const int len=start.length();
        bool finish=false;
        int level=1;
        while(!cur.empty() && !finish){
            for(auto s:cur)
                dict.erase(s);
            for(auto s:cur){
                string cp=s;
                for(int i=0; i<len; ++i){
                    for(char c='a'; c<='z'; ++c){
                        if(c==s[i]) continue;
                        s[i]=c;
                        if(s==end){
                            finish=true;
                            prev[end].push_back(cp);
                        }else if(dict.count(s)){
                            next.insert(s);
                            prev[s].push_back(cp);
                        }
                        s[i]=cp[i];
                    }
                }
            }
            ++level;
            cur.clear();
            cur.swap(next);
        }
        if(prev.count(end)){
            vector<string> path;
            path.push_back(end);
            trace(res, prev, path, start, level);
        }
        return res;
    }
private:
    void trace(vector<vector<string>> &res, map<string, vector<string>> &prev, vector<string> &path, string &start, int level){
        if(path.size()==level){
            if(path.back()==start){
                res.push_back(path);
                reverse(res.back().begin(), res.back().end());
            }
            return;
        }
        string cur=path.back();
        for(auto s:prev[cur]){
            path.push_back(s);
            trace(res, prev, path, start, level);
            path.pop_back();
        }
    }
};
