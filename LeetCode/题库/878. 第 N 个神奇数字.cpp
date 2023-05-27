const int mod=1e9+7;
typedef long long ll;
class Solution {
public:
    ll cal(ll x,ll a,ll b)
    {
        ll res=0;
        res+=x/a;
        res+=x/b;
        res-=x/(a/__gcd(a,b)*b);
        return res;
    }
    int nthMagicalNumber(int n, int a, int b) {
        ll l,r,mid;
        l=1;
        r=1ll*n*min(a,b);
        while(l<r)
        {
            mid=(l+r)>>1;
            if(cal(mid,a,b)>=n) r=mid;
            else l=mid+1;
        }
        return l%mod;
    }
};
