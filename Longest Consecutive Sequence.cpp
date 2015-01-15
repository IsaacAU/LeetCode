class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> set;
        for(auto i:num)
            set.insert(i);
        int res=0;
        for(auto i:num){
            if(set.count(i)){
                set.erase(i);
                int x=i-1, cnt=1;
                while(set.count(x)){
                    set.erase(x);
                    --x;
                    ++cnt;
                }
                x=i+1;
                while(set.count(x)){
                    set.erase(x);
                    ++x;
                    ++cnt;
                }
                res=max(res, cnt);
            }
            if(set.empty())
                break;
        }
        return res;
    }
};
