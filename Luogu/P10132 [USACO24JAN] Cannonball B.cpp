#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
map<int,int> mp[MAX];
int q[MAX],v[MAX],flag[MAX];
int main()
{
	int n,pos,now,i,ans,d;
	scanf("%d%d",&n,&pos);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&q[i],&v[i]);
		flag[i]=0;
		mp[i].clear();
	}
	ans=0;
	d=1;
	now=1;
	while(pos>=1&&pos<=n)
	{
		if(mp[pos].count(d*now)) break;
		mp[pos][d*now]=1;
		if(q[pos]==0)
		{
			now+=v[pos];
			d*=-1;
		}
		else
		{
			if(!flag[pos]&&now>=v[pos])
			{
				flag[pos]=1;
				ans++;
			}
		}
		pos+=d*now;
	}
	printf("%d\n",ans);
	return 0;
}
