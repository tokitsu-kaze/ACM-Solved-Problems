class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l,r,mid;
        l=1;
        r=1e9;
        while(l<r)
        {
            mid=(l+r)>>1;
            if((mid+1)*(mid+1)<=num) l=mid+1;
            else r=mid;
        }
        return l*l==num;
    }
};
