#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,m,i,la,ra,lb,rb,ua,ub;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		la=1;
		ra=n;
		lb=1;
		rb=m;
		ua=ub=0;
		vector<ll> res;
		ans=0;
		set<ll> sa,sb;
		while(1)
		{
			if(ra<la && rb<lb) break;
			if(ra-la+1-ua<=1 && rb-lb+1-ub<=1) break;
			if(ra-la+1-ua>1 && rb-lb+1-ub>1)
			{
				if(a[ra]-a[la]>b[rb]-b[lb])
				{
					ans+=a[ra]-a[la];
					sa.insert(a[ra]-a[la]);
					ub++;
					la++;
					ra--;
				}
				else
				{
					ans+=b[rb]-b[lb];
					sb.insert(b[rb]-b[lb]);
					ua++;
					lb++;
					rb--;
				}
			}
			else if(ra-la+1-ua>1)
			{
				if(rb-lb+1-ub==0 && sb.size()>0)
				{
					ans-=*sb.begin();
					sb.erase(sb.begin());
					lb--;
					rb++;
					ua--;
					ans+=a[ra]-a[la];
					sa.insert(a[ra]-a[la]);
					ub++;
					la++;
					ra--;
				}
				if(ra-la+1-ua>1 && rb-lb+1-ub>=1)
				{
					ans+=a[ra]-a[la];
					sa.insert(a[ra]-a[la]);
					ub++;
					la++;
					ra--;
				}
				else break;
			}
			else if(rb-lb+1-ub>1)
			{
				if(ra-la+1-ua==0 && sa.size()>0)
				{
					ans-=*sa.begin();
					sa.erase(sa.begin());
					la--;
					ra++;
					ub--;
					ans+=b[rb]-b[lb];
					sb.insert(b[rb]-b[lb]);
					ua++;
					lb++;
					rb--;
				}
				if(rb-lb+1-ub>1 && ra-la+1-ua>=1)
				{
					ans+=b[rb]-b[lb];
					sb.insert(b[rb]-b[lb]);
					ua++;
					lb++;
					rb--;
				}
				else break;
			}
			res.push_back(ans);
		}
		printf("%d\n",(int)res.size());
		for(i=0;i<res.size();i++) printf("%lld%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
