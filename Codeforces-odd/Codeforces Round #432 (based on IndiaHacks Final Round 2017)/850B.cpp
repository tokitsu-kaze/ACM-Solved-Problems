#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
ll a[MAX],s[MAX];
int main()
{
	ll n,i,j,x,y,p,temp,ans;
	while(~scanf("%lld%lld%lld",&n,&x,&y))
	{
		p=x/y;
		mem(a,0);
		mem(s,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&temp);
			a[temp]++;
			s[temp]+=temp;
		}
		for(i=1;i<=2e6;i++)
		{
			a[i]+=a[i-1];
			s[i]+=s[i-1];
		}
		ans=LLINF;
		for(i=2;i<=1e6;i++)
		{
			temp=0;
			for(j=i;j<=2e6;j+=i)
			{
				if(temp>=ans) break;
				ll k=max(j-i+1,j-p);
				temp+=((a[j]-a[k-1])*j-(s[j]-s[k-1]))*y+(a[k-1]-a[j-i])*x;
			}
			ans=min(ans,temp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}