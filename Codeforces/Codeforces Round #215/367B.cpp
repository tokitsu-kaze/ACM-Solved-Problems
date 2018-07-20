#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX],ans[MAX];
map<int,int> mm,mp;
int main()
{
	int n,m,p,i,x,cnt,l,r;
	while(~scanf("%d%d%d",&n,&m,&p))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		mm.clear();
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			mm[x]++;
		}
		cnt=0;
		for(i=1;i<=p;i++)
		{
			mp.clear();
			l=i;
			int tag=0;
			for(r=i;r<=n;r+=p)
			{
				if(tag==m)
				{
					tag--;
					mp[a[l]]--;
					if(mp[a[l]]==0) mp.erase(a[l]);
					l+=p;
				}
				mp[a[r]]++;
				tag++;
				if(tag==m)
				{
					if(mp==mm) ans[cnt++]=l;
				}
			}
		}
		sort(ans,ans+cnt);
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			if(i==cnt-1) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}