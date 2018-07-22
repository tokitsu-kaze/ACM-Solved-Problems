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
struct node
{
	int id,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
}f[250*250+10],com[250*250+10];
int ans[250*250+10];
int main()
{
	int f1,a,b,c,m,n,cnt,i,j,x,temp;
	while(~scanf("%d%d%d%d",&f1,&a,&b,&c))
	{
		map<int,int> mp;
		map<int,int> ::iterator it;
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				mp[x]++;
			}
		}
		cnt=1;
		for(it=mp.begin();it!=mp.end();it++)
		{
			com[cnt].id=it->fi;
			com[cnt++].v=it->se;
		}
		cnt--;
		sort(com+1,com+1+cnt);
		f[1].v=f1;
		f[1].id=1;
		for(i=2;i<=cnt;i++)
		{
			f[i].id=i;
			f[i].v=(a*f[i-1].v+b)%c+1;
		}
		sort(f+1,f+1+cnt);
		mem(ans,0);
		for(i=1;i<=cnt;i++)
		{
			ans[f[i].id]=com[i].id;
		}
		printf("%d\n",cnt);
		for(i=1;i<=cnt;i++)
		{
			if(i==cnt) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}
/*
1 3 1 5
4 4
1 2 3 6
2 4 1 5
3 1 9 3
2 8 7 2
*/