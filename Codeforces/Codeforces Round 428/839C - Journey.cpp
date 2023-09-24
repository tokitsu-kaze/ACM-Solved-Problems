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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
double ans;
void dfs(int x,int pre,int len,double g)
{
	int i,flag=0,sz=sz(mp[x]);
	if(pre!=0) sz--;
	for(i=0;i<sz(mp[x]);i++)
	{
		if(mp[x][i]!=pre)
		{
			flag=1;
			dfs(mp[x][i],x,len+1,g/(1.0*sz));
		}
	}
	if(flag==0)
	{
	//	cout<<len<<" "<<g<<endl;
		ans+=len*g;
	}
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=0;
		dfs(1,0,0,1);
		printf("%.10lf\n",ans);
	}
	return 0;
}