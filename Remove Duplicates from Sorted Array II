class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int pos=-1, cur=A[0], cnt=1;
        for(int i=1; i<n; ++i){
            if(A[i]==cur)
                ++cnt;
            else{
                cur=A[i];
                cnt=1;
            }
            if(pos>=0 && cnt<3)
                A[pos++]=A[i];
            if(cnt==3 && pos<0)
                pos=i;
        }
        return pos<0?n:pos;
    }
};
