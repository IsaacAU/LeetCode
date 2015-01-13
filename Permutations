class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(begin(num), end(num));
        vector<vector<int>> res;
        do{
            res.push_back(num);
        }while(next_permutation(begin(num), end(num)));
        return res;
    }
};
