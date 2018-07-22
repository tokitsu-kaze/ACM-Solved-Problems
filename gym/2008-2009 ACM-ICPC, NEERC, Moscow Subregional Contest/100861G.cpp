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
const int MAX=3e5+10;
const ll mod=1e9+7;
pair<double,double> p[1010],mid;
map<pair<double,double>,int> mp;
int main()
{
	int n,i,j,flag;
	double x,y;
	while(~scanf("%d",&n))
	{
		mp.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x,&y);
			p[i]=MP(x,y);
		}
		if(n==3)
		{
			puts("0");
			continue;	
		}
		flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				mid=MP((p[i].fi+p[j].fi)/2,(p[i].se+p[j].se)/2);
				mp[mid]++;
				if(mp[mid]==2) flag=1;
			}
		}
		if(flag)
		{
			puts("1");
			continue;
		}
		else if(n>=4) flag=2;
		printf("%d\n",flag);
	}
	return 0;
}