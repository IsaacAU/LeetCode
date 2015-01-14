class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> lib{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path;
        search(lib, digits, res, path, 0);
        return move(res);
    }
private:
    void search(vector<string> &lib, string &digits, vector<string> &res, string &path, int cur){
        if(cur==digits.length()){
            res.push_back(path);
            return;
        }
        string &sub=lib[digits[cur]-'0'];
        for(auto c:sub){
            path.push_back(c);
            search(lib, digits, res, path, cur+1);
            path.pop_back();
        }
    }
};
