class Solution {
public:
    // hash table O(nlogn)
    int majorityElement1(vector<int> &num) {
        unordered_map<int, int> m;
        const int n=num.size();
        for(auto i:num){
            m[i]++;
            if(m[i]>n/2)
                return i;
        }
        return 0;
    }
    // Moore's Voting Algorithm O(n)
    int majorityElement2(vector<int> &num) {
        int Major=num[0], count=1;
        for(int i=1; i<num.size(); ++i){
            if(num[i]==Major)
                ++count;
            else
                --count;
            if(count==0){
                Major=num[i];
                count=1;
            }
        }
        return Major;
    }
};
