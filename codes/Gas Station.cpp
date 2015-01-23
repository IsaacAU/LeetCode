class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total=0, idx=0, sum=0;
        for(int i=0; i<gas.size(); ++i){
            int diff=gas[i]-cost[i];
            total+=diff;
            sum+=diff;
            if(sum<0){
                idx=i+1;
                sum=0;
            }
        }
        if(total<0)
            return -1;
        return idx;
    }
};
