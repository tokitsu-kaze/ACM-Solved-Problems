class Solution {
    
    int cal(int n,int m,int x)
    {
        int i,res;
        res=0;
        for(i=1;i<=n;i++) res+=min(m,x/i);
        return res;
    }

public:
    int findKthNumber(int m, int n, int k) {
        int l,r,mid;
        l=1;
        r=n*m;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(cal(n,m,mid)>=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
