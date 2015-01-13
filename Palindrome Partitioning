class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int len=s.length();
        vector<vector<bool>> isPalin(len, vector<bool>(len, false));
        for(int i=len-1; i>=0; --i){
            isPalin[i][i]=true;
            for(int j=i+1; j<len; ++j)
                isPalin[i][j]= (j==i+1 || isPalin[i+1][j-1]) && s[i]==s[j];
        }
        vector<vector<string>> res;
        vector<string> path;
        search(s, isPalin, 0, path, res);
        return move(res);
    }
private:
    void search(const string &s, vector<vector<bool>> &isPalin, int pos, vector<string> &path, vector<vector<string>> &res){
        const int len=s.length();
        if(pos==len){
            res.push_back(path);
            return;
        }
        for(int i=pos; i<len; ++i){
            if(isPalin[pos][i]){
                path.push_back(s.substr(pos, i-pos+1));
                search(s, isPalin, i+1, path, res);
                path.pop_back();
            }
        }
    }
};
