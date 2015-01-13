class Solution {
public:
    string countAndSay(int n) {
        string cur, next("1");
        while(--n){
            cur.clear();   cur.swap(next);
            char digit=cur[0];
            int cnt=1;
            for(int i=1; i<cur.length(); ++i){
                if(cur[i]!=cur[i-1]){
                    next.push_back('0'+cnt);
                    next.push_back(digit);
                    digit=cur[i];
                    cnt=1;
                }else{
                    ++cnt;
                }
            }
            next.push_back('0'+cnt);
            next.push_back(digit);
        }
        return next;
    }
};
