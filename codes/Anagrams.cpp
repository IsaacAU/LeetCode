class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if(strs.empty())    return res;
        map<string, vector<int>> m;
        for(int i=0; i<strs.size(); ++i){
            string s=strs[i];
            sort(begin(s), end(s));
            m[s].push_back(i);
        }
        for(auto p:m){
            if(p.second.size()>1){
                for(auto i:p.second){
                    res.push_back(strs[i]);
                }
            }
        }
        return res;
    }
};
