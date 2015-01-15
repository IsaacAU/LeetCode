class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<int>> m;
        for(int i=0; i<strs.size(); ++i){
            string s=strs[i];
            sort(begin(s), end(s));
            m[s].push_back(i);
        }
        vector<string> res;
        for(auto it=begin(m); it!=end(m); ++it){
            if(it->second.size()>1){
                for(int i=0; i<it->second.size(); ++i)
                    res.push_back(strs[it->second.at(i)]);
            }
        }
        return res;
    }
private:
    bool isAnagram(const string &s1, const string &s2){
        if(s1.length()!=s2.length())    return false;
        const int nc=26;
        int arr[nc];
        fill_n(arr, nc, 0);
        for(int i=0; i<s1.length(); ++i){
            arr[unsigned(s1[i]-'a')]++;
            arr[unsigned(s2[i]-'a')]--;
        }
        for(int i=0; i<nc; ++i)
            if(arr[i])  return false;
        return true;
    }
};
