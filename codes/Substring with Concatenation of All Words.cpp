class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if(S.empty() || L.empty())  return res;
        map<string, int> um;
        for(auto s:L)
            ++um[s];
        int each=L[0].length(), n=L.size();
        for(int i=0; i+n*each<=S.length(); ++i){
            map<string, int> m(um);
            for(int j=0; j<n; ++j){
                string sub=S.substr(i+j*each, each);
                if(m.count(sub)){
                    if(--m[sub]==0)
                        m.erase(sub);
                }else
                    break;
            }
            if(m.empty())   res.push_back(i);
        }
        return res;
    }
};
