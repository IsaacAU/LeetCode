class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1)    return s;
        vector<string> vs(nRows, "");
        int base=2*nRows-2;
        for(int i=0; i<s.length(); ++i){
            int r=i%base;
            if(r<nRows) vs[r].push_back(s[i]);
            else{
                vs[base-r].push_back(s[i]);
            }
        }
        string res;
        for(auto ss:vs) res+=ss;
        return res;
    }
};
