class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        search(res, n, 0, path);
        return res;
    }
private:
    void search(vector<string> &res, int n, int left, string &path){
        if(path.length()==2*n){
            res.push_back(path);
            return;
        }
        if(left<n){
            path.push_back('(');
            search(res, n, left+1, path);
            path.pop_back();
        }
        if(path.length()<2*left){
            path.push_back(')');
            search(res, n, left, path);
            path.pop_back();
        }
    }
};
