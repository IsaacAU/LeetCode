class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for(int i=1; i<=n; ++i)
            for(int j=(1<<i-1)-1; j>=0; --j)
                res.push_back((1<<i-1)+res[j]);
        return move(res);
    }
};





// IMPORTANT: precedence    (+,-) > (>>,<<)
//            so, (1<<i-1)-1    parentheses is necessary!!!!
