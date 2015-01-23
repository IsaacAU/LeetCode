class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i=0; i<numbers.size(); ++i){
            if(m.count(numbers[i])){
                res.push_back(m[numbers[i]]);
                res.push_back(i+1);
                break;
            }else{
                m[target-numbers[i]]=i+1;
            }
        }
        return res;
    }
};
