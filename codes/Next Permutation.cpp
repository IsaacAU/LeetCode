class Solution {
public:
    void nextPermutation(vector<int> &num) {
        auto it=adjacent_find(num.rbegin(), num.rend(), [](int x, int y){return x>y;}).base();
        if(it==begin(num)){ reverse(num.begin(), num.end()); return; }
        auto x=prev(it);
        auto y=find_if(num.rbegin(), reverse_iterator<vector<int>::iterator>(x), [&x](int t){ return t>*prev(x); }).base();
        swap(*prev(x), *prev(y));
        sort(x, num.end());
    }
};
