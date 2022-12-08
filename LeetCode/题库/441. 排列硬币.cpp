class Solution {
public:
    int arrangeCoins(int n) {
        long long l,r,mid;
        l=1;
        r=n;
        while(l<r)
        {
            mid=(l+r)>>1;
            if((mid+2)*(mid+1)/2<=n) l=mid+1;
            else r=mid;
        }
        return (int)l;
    }
};
