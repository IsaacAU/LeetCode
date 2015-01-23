class Solution {
public:
    int findMin(vector<int> &num) {
        int i=0, j=num.size()-1;
        while(i<=j){
            if(num[i]<=num[j])
                return num[i];
            else{
                int m=(i+j)/2;
                if(num[m]>=num[i])
                    i=m+1;
                else
                    j=m;
            }
        }
    }
};
