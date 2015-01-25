class Solution {
public:
    // hashmap
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> um;
        vector<int> res{-1,-1};
        for(int i=0; i<numbers.size(); ++i){
            if(um.count(numbers[i])){
                res[0]=um[numbers[i]];
                res[1]=i+1;
                break;
            }else{
                um[target-numbers[i]]=i+1;
            }
        }
        return res;
    }
    // two pointer
    vector<int> twoSum(vector<int> &numbers, int target) {
        const int n=numbers.size();
        vector<int> idx;    idx.reserve(n);
        for(int i=0; i<n; ++i)
            idx.push_back(i);
        sort(begin(idx), end(idx), [&numbers](int i, int j){ return numbers[i]<numbers[j]; });
        int i=0, j=n-1;
        vector<int> res{-1,-1};
        while(i<j){
            int sum=numbers[idx[i]]+numbers[idx[j]];
            if(sum==target){
                res[0]=min(idx[i],idx[j])+1;
                res[1]=max(idx[i],idx[j])+1;
                break;
            }else if(sum<target)
                ++i;
            else
                --j;
        }
        return res;
    }
};
