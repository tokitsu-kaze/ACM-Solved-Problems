#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int n,k,id[128],tot;
char a[MAX],b[MAX];
ll ans;
void dfs(int x,int now)
{
	if(__builtin_popcount(now)>k) return;
	if(x==tot)
	{
		int i,cnt;
		ll res;
		cnt=0;
		res=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==b[i] || (((now>>id[a[i]])&1))) cnt++;
			else
			{
				res+=1LL*cnt*(cnt+1)/2;
				cnt=0;
			}
		}
		res+=1LL*cnt*(cnt+1)/2;
		ans=max(ans,res);
		return;
	}
	dfs(x+1,now);
	dfs(x+1,now|(1<<x));
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(id,-1,sizeof id);
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(id[a[i]]==-1) id[a[i]]=tot++;
		}
		ans=0;
		dfs(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
