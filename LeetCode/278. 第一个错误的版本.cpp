// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l,r,mid;
        l=1;
        r=n;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(mid>n)
            {
                r=mid;
                continue;
            }
            if(!isBadVersion(mid)) l=mid+1;
            else r=mid;
        }
        return (int)l;
    }
};
