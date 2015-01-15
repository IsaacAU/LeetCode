class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start==end)  return 1;
        queue<string> q;
        q.push(start);
        int level=1, next=0, cur=1;
        const int len=start.length();
        while(!q.empty()){
            string s=q.front();  q.pop();
            for(int i=0; i<len; ++i){
                char old=s[i];
                for(char c='a'; c<='z'; ++c){
                    if(c==old)  continue;
                    s[i]=c;
                    if(s==end)  return level+1;
                    if(dict.count(s)){
                        q.push(s);
                        dict.erase(s);
                        ++next;
                    }
                }
                s[i]=old;
            }
            if(--cur==0){
                ++level;
                cur=next;
                next=0;
            }
        }
        return 0;
    }
};
