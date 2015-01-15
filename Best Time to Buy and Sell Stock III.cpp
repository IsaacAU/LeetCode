class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())  return 0;
        int n=prices.size();
        vector<int> left(n,0), right(n,0);
        int minPrice=prices[0];
        for(int i=1; i<n; ++i){
            if(prices[i]<minPrice)
                minPrice=prices[i];
            left[i]=max(left[i-1], prices[i]-minPrice);
        }
        int maxPrice=prices[n-1];
        for(int i=n-2; i>=0; --i){
            if(prices[i]>maxPrice)
                maxPrice=prices[i];
            right[i]=max(right[i+1], maxPrice-prices[i]);
        }
        int maxProfit=0;
        for(int i=0; i<n; ++i){
            if(left[i]+right[i]>maxProfit)
                maxProfit=left[i]+right[i];
        }
        return maxProfit;
    }
};
