class Solution {
public:
    // use two vectors
    int candy1(vector<int> &ratings) {
        int len=ratings.size();
        if(len==0)  return 0;
        if(len==1)  return 1;
        vector<int> left(len, 1), right(len, 1);
        for(int i=1; i<len; ++i)
            if(ratings[i]>ratings[i-1]) 
                left[i]=left[i-1]+1;
        int sum=0;
        for(int i=len-1; i>=0; --i){
            if(i<len-1 && ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
            sum+=max(left[i], right[i]);
        }
        return sum;
    }
    // use one vector
    int candy2(vector<int> &ratings) {
        int len=ratings.size();
        if(len==0)  return 0;
        if(len==1)  return 1;
        vector<int> left(len, 1);
        for(int i=1; i<len; ++i)
            if(ratings[i]>ratings[i-1]) 
                left[i]=left[i-1]+1;
        int sum=0;
        for(int i=len-1; i>=0; --i){
            sum+=(i<len-1 && ratings[i]>ratings[i+1] && left[i+1]+1>left[i])?left[i+1]+1:left[i];
            left[i]=(i<len-1 && ratings[i]>ratings[i+1])?left[i+1]+1:1;
        }
        return sum;
    }
};
