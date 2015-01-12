class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        const int n=L.size(), each=L[0].length(), len=S.length();
        unordered_map<string, int> m;
        for(int i=0; i<n; ++i)
            ++m[L[i]];
        vector<int> res;
        for(int i=0; i<=len-n*each; ++i){
            unordered_map<string, int> mm(m);
            search(S, i, i, mm, res);
        }
        return move(res);
    }
private:
    void search(string &S, int start, int cur, unordered_map<string,int> &m, vector<int> &res){
        if(m.empty()){
            res.push_back(start);
            return;
        }
        const int each=begin(m)->first.length();
        string sub=S.substr(cur, each);
        if(m.count(sub)){
            if(--m[sub]==0) m.erase(sub);
            cur+=each;
            search(S, start, cur, m, res);
            cur-=each;
            ++m[sub];
        }
    }
};
