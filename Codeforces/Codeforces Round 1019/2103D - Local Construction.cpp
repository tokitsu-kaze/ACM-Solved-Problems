#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> ra[MAX],rb[MAX];
int res[MAX];
int main()
{
	int T,n,i,x,mx,tot,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			ra[i].clear();
			rb[i].clear();
		}
		mx=0;
		p=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==-1)
			{
				x=0;
				p=i;
			}
			mx=max(mx,x);
			if(p==0) ra[x].push_back(i);
			else rb[x].push_back(i);
		}
		tot=0;
		for(i=2;i<=(mx/2*2);i+=2)
		{
			reverse(rb[i].begin(),rb[i].end());
			for(auto &it:ra[i]) res[it]=++tot;
			for(auto &it:rb[i]) res[it]=++tot;
		}
		
		res[p]=++tot;
		
		if(!(mx&1)) mx--;
		for(i=mx;i>=1;i-=2)
		{
			reverse(ra[i].begin(),ra[i].end());
			for(auto &it:ra[i]) res[it]=++tot;
			for(auto &it:rb[i]) res[it]=++tot;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}

